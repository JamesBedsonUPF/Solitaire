/*
  ==============================================================================

    Stone.h
    Created: 24 Dec 2021 4:30:22pm
    Author:  James Bedson

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
enum Field{
    invalid = -1,
    empty = 0,
    present = 1
};

class Stone  : public juce::Component
{
public:
    Stone();
    ~Stone() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void setField(Field value);
    int getField();
    void mouseEnter(const juce::MouseEvent &event) override;
    void mouseExit(const juce::MouseEvent &event) override;
    void mouseDown(const juce::MouseEvent &event) override;
    bool isEntered {false};
    bool isSelected {false};

private:
    Field field;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Stone)
};

