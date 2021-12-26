/*
  ==============================================================================

    Board.h
    Created: 24 Dec 2021 3:08:19pm
    Author:  James Bedson

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "Stone.h"
#define SIZE 7

//==============================================================================
/*
*/

class Board {
public:
    Board();
    ~Board();
    int getSize();
    static std::vector<std::vector<std::unique_ptr<Stone>>> stones;
    void initBoard();
    static void makeMove();
    static bool twoSelected();
    static void increaseSelected();
    static void decreaseSelected();
    static void resetSelected();

private:
    static const int size = SIZE;
    static int selectedStones;
};

