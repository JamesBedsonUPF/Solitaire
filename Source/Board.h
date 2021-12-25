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
class Board
{
public:
    Board();
    ~Board();
    int getSize();
    std::vector<std::vector<std::unique_ptr<Stone>>> stones;
    void initBoard();
private:
    int size = SIZE;
};
