/*
  ==============================================================================

    MainMenu.h
    Created: 25 Dec 2021 9:39:02pm
    Author:  James Bedson

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MainMenu  : public juce::Component
{
public:
    MainMenu();
    ~MainMenu() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    juce::TextButton button {"Play"};
    juce::Label label{"Solitaire", "Solitaire"};

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainMenu)
};
