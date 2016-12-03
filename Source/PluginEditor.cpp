/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
HighPassFilterAudioProcessorEditor::HighPassFilterAudioProcessorEditor (HighPassFilterAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
	setSize (400, 300);
	addAndMakeVisible(knob1 = new Slider("Knob - 1"));

	//knob1 // Cutoff
	knob1->setRange(20, 10000);
	knob1->setTextBoxStyle(Slider::TextBoxBelow, false, 60, 15);
	knob1->setTextValueSuffix(" hz");
	knob1->setSliderStyle(Slider::Rotary);
	knob1->setColour(Slider::rotarySliderFillColourId, Colours::grey);
	knob1->setColour(Slider::rotarySliderOutlineColourId, Colours::white);
	knob1->addListener(this);
	knob1->setBounds(150, 90, 90, 90);

	startTimer(50);
}

HighPassFilterAudioProcessorEditor::~HighPassFilterAudioProcessorEditor()
{
	knob1 = nullptr;
}

//==============================================================================
void HighPassFilterAudioProcessorEditor::paint (Graphics& g)
{
	g.fillAll(Colours::darkblue);
	g.setColour(Colours::white);
	g.setFont(Font("Arial", 13, Font::bold + Font::italic));
	//knob text
	g.drawSingleLineText("Cutoff", 182, 80); //this is knob 1
}

void HighPassFilterAudioProcessorEditor::timerCallback()
{
	knob1->setValue(processor.getParameter(HighPassFilterAudioProcessor::knob1Param), NotificationType::dontSendNotification);
}

void HighPassFilterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void HighPassFilterAudioProcessorEditor::sliderValueChanged(Slider* sliderThatWasChanged)
{
	if (sliderThatWasChanged == knob1)
	{
		processor.setParameterNotifyingHost(HighPassFilterAudioProcessor::knob1Param, (float)knob1->getValue());
	}
}