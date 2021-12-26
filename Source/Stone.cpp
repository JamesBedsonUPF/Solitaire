/*
  ==============================================================================

    Stone.cpp
    Created: 24 Dec 2021 4:30:22pm
    Author:  James Bedson

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Stone.h"

//==============================================================================
Stone::Stone()
{
    field = present;
}

Stone::~Stone()
{
}

void Stone::paint (juce::Graphics& g)
{
    juce::Rectangle<float> rectangle(10,10,20,20);
    if (field == present){
        if (isSelected){
            g.drawEllipse(rectangle, 4);
            g.setColour(juce::Colours::firebrick);
            g.fillEllipse(rectangle);
        }
        else if (isEntered && !isSelected){
            g.drawEllipse(rectangle, 1);
            g.setColour(juce::Colours::grey);
            g.fillEllipse(rectangle);
        }
        else {
            g.drawEllipse(rectangle, 1);
            g.setColour(juce::Colours::darkgrey);
            g.fillEllipse(rectangle);
        }
    }
    else if (field == empty){
        if (isSelected){
            g.drawEllipse(rectangle, 4);
            g.setColour(juce::Colours::white);
            g.fillEllipse(rectangle);
        }
        else{
            g.drawEllipse(rectangle, 1);
            g.setColour(juce::Colours::white);
            g.fillEllipse(rectangle);
        }


    }
    else if (field == invalid){
        return;
    }

}
void Stone::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
}

void Stone::setField(Field value) {this->field = value;}
int Stone::getField(){return field;}
void Stone::mouseEnter(const juce::MouseEvent &event) {
    isEntered = true;
    repaint();
}
void Stone::mouseExit(const juce::MouseEvent &event) {
    isEntered = false;
    repaint();
}
void Stone::mouseDown(const juce::MouseEvent &event) {
    if (isSelected && (field == present || field == empty)){
        isSelected = false;
        Board::decreaseSelected();
    }
    else if (!isSelected && (field == present || field == empty)){
        isSelected = true;
        Board::increaseSelected();
    }
    else{
        return;
    }

    if (Board::twoSelected()){
        Board::makeMove();
        Board::resetSelected();
    }
    repaint();
}


