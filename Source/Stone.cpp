#pragma once
#include "Stone.h"

//==============================================================================
Stone::Stone(){field = present;}

Stone::~Stone(){}

//
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
void Stone::resized(){}

void Stone::setField(Field value) {this->field = value;}
int Stone::getField(){return field;}

//Mouse Action
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
        SelectionCounter::decreaseSelected();
    }
    else if (!isSelected && (field == present || field == empty)){
        isSelected = true;
        SelectionCounter::increaseSelected();
    }
    else{
        return;
    }
    repaint();
}


