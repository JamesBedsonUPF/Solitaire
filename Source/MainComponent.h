#include <JuceHeader.h>
#include "MainMenu.h"
#include "Board.h"
#include "SelectionCounter.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component, public juce::Timer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void setupGridBoard();
    void setupMenu();
    void timerCallback() override;
    void gameplay();

private:
    //==============================================================================
    // Your private member variables go here...
    Board mBoard;
    MainMenu menu;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
