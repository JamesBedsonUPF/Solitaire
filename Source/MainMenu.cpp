/*
  ==============================================================================

    MainMenu.cpp
    Created: 25 Dec 2021 9:39:02pm
    Author:  James Bedson

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MainMenu.h"

//==============================================================================
MainMenu::MainMenu()
{
    addAndMakeVisible(button);
    addAndMakeVisible(label);
}

MainMenu::~MainMenu()
{
}

void MainMenu::paint (juce::Graphics& g)
{
    juce::Colour c((uint8_t)100, (uint8_t)100,(uint8_t)100, 0.9f);
    g.fillAll(c);

    juce::Rectangle<int> h(getLocalBounds().getCentreX() - 200, 0, 400, 50);
    g.setColour(juce::Colours::firebrick);
    g.fillRect(h);
}

void MainMenu::resized()
{
    juce::Rectangle<int> r(getLocalBounds().getCentreX() - 125, getLocalBounds().getCentreY() - 25, 250, 50);
    button.setBounds(r);

    juce::Rectangle<int> h(getLocalBounds().getCentreX() - 200, 0, 400, 50);
    label.setJustificationType(juce::Justification::centred);
    label.setBounds(h);
}
