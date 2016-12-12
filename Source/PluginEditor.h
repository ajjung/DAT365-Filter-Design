/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class HighPassFilterAudioProcessorEditor  : public AudioProcessorEditor,
	Slider::Listener,
	Timer

{
public:
    HighPassFilterAudioProcessorEditor (HighPassFilterAudioProcessor&);
    ~HighPassFilterAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
	void timerCallback()override;
	void sliderValueChanged(Slider* sliderThatWasChanged) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    HighPassFilterAudioProcessor& processor;
	ScopedPointer<Slider> knob1;
	ScopedPointer<Slider> knob2;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HighPassFilterAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
