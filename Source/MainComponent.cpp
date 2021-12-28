#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent(){
    setSize (600, 400);

    for (int i = 0; i < mBoard.getSize(); i++){
        for (int j = 0; j < mBoard.getSize(); j++){
            addAndMakeVisible(*mBoard.stones.at(i).at(j));
        }
    }
    addAndMakeVisible(menu);
    startTimerHz(60);
}

MainComponent::~MainComponent(){
    stopTimer();
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::white);
}

void MainComponent::resized()
{
    setupGridBoard();
    //setupMenu();
}

void MainComponent::timerCallback(){

    gameplay();
}

void MainComponent::setupGridBoard() {
    using Track = juce::Grid::TrackInfo;
    using Fr = juce::Grid::Fr;

    juce::Rectangle<int> bounds(getLocalBounds().getWidth()/2 - 200, getLocalBounds().getHeight()/2 - 200, 400,400);
    juce::Grid grid;
    grid.justifyContent = juce::Grid::JustifyContent::center;

    for (int i = 0; i < mBoard.getSize(); i++){
        grid.templateColumns.add(Track(Fr(1)));
        grid.templateRows.add(Track(Fr(1)));
    }

    juce::Array<juce::GridItem> items;

    for (int i = 0; i < mBoard.getSize(); i++){
        for (int j = 0; j < mBoard.getSize(); j++){
            items.add(juce::GridItem(*mBoard.stones.at(i).at(j)));
        }
    }
    grid.items = items;
    grid.performLayout(bounds);
}
void MainComponent::setupMenu(){

    menu.setBounds(getLocalBounds());

}
void MainComponent::gameplay() {

    if (SelectionCounter::twoSelected()){
        mBoard.makeMove();
        SelectionCounter::resetSelected();
    }
}
