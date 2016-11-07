/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <string.h>


//==============================================================================
HighPassFilterAudioProcessor::HighPassFilterAudioProcessor(): m_knob1(0)
{
	m_fCutoff = m_knob1;
}

HighPassFilterAudioProcessor::~HighPassFilterAudioProcessor()
{
}

//==============================================================================
const String HighPassFilterAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int HighPassFilterAudioProcessor::getNumParameters()
{
	return totalNumParams;
}

float HighPassFilterAudioProcessor::getParameter(int index)
{
	switch (index) {
	case knob1Param: return m_knob1;
	default: return 0.0;
	}
}

void HighPassFilterAudioProcessor::setParameter(int index, float newValue)
{
	switch (index) {
	case knob1Param: m_knob1 = newValue;
		m_fCutoff = m_knob1;

	default: break;
	}
}

const String HighPassFilterAudioProcessor::getParameterName(int index)
{
	switch (index){
	case knob1Param: return "Cutoff";
	default: return String::empty;
	}
}

const String HighPassFilterAudioProcessor::getParameterText(int index)
{
	return String(getParameter(index), 2);
}

const String HighPassFilterAudioProcessor::getInputChannelName(int channelIndex) const
{
	return String(channelIndex + 1);
}

const String HighPassFilterAudioProcessor::getOutputChannelName(int channelIndex) const
{
	return String(channelIndex + 1);
}

bool HighPassFilterAudioProcessor::isInputChannelStereoPair(int index) const
{
	return true;
}

bool HighPassFilterAudioProcessor::isOutputChannelStereoPair(int index) const
{
	return true;
}


bool HighPassFilterAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool HighPassFilterAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool HighPassFilterAudioProcessor::silenceInProducesSilenceOut() const
{
	return false;
}

double HighPassFilterAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int HighPassFilterAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int HighPassFilterAudioProcessor::getCurrentProgram()
{
    return 0;
}

void HighPassFilterAudioProcessor::setCurrentProgram (int index)
{
}

const String HighPassFilterAudioProcessor::getProgramName (int index)
{
    return String();
}

void HighPassFilterAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void HighPassFilterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	m_fCutoff = m_knob1;
}

void HighPassFilterAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool HighPassFilterAudioProcessor::setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet)
{
    // Reject any bus arrangements that are not compatible with your plugin

    const int numChannels = preferredSet.size();

   #if JucePlugin_IsMidiEffect
    if (numChannels != 0)
        return false;
   #elif JucePlugin_IsSynth
    if (isInput || (numChannels != 1 && numChannels != 2))
        return false;
   #else
    if (numChannels != 1 && numChannels != 2)
        return false;

    if (! AudioProcessor::setPreferredBusArrangement (! isInput, bus, preferredSet))
        return false;
   #endif

    return AudioProcessor::setPreferredBusArrangement (isInput, bus, preferredSet);
}
#endif

void HighPassFilterAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);
		for (int i = 0; i < buffer.getNumSamples(); i++)
		{
			if (channel == 0)
			{
				channelData[i] = filter.highpass(channelData[i], z0, p0, theta0);
			}

			if (channel == 1)
			{
				channelData[i] = filter.highpass(channelData[i], z0, p0, theta0);
			}
		}
    }    
	for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
}

//==============================================================================
bool HighPassFilterAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* HighPassFilterAudioProcessor::createEditor()
{
    return new HighPassFilterAudioProcessorEditor (*this);
}

//==============================================================================
void HighPassFilterAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void HighPassFilterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new HighPassFilterAudioProcessor();
}
