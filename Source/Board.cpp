/*
  ==============================================================================

    Board.cpp
    Created: 24 Dec 2021 3:08:19pm
    Author:  James Bedson

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Board.h"

//==============================================================================
Board::Board()
{
    stones = std::vector<std::vector<std::unique_ptr<Stone>>>(size);
    for (auto& element : stones){
        element.resize(size);
    }

    for (int i = 0; i < stones.size(); i++){
        for (int j = 0; j < stones.size(); j++){
            stones[i][j] = std::make_unique<Stone>();
        }
    }

    initBoard();
}

Board::~Board(){}

int Board::getSize(){return (int)stones.size();}
void Board::initBoard() {
    for (int i = 0; i < 2; i++){
        int j = 0;
        while (j <= 6){
            stones[i][j]->setField(invalid);
            if (j == 1){
                j = 4;
            }
            j++;
        }
    }

    for (int i = 5; i <= 6; i++){
        int j = 0;
        while (j <= 6){
            stones[i][j]->setField(invalid);
            if (j == 1){
                j = 4;
            }
            j++;
        }
    }
    stones[3][3]->setField(empty);
}
void Board::makeMove() {
    for (int i = 0; i < size - 2; i++){
        for (int j = 0; j < size - 2; j++){
            // Same Row
            if (stones[i][j]->isSelected && stones[i][j+2]->isSelected){
                if ((stones[i][j]->getField() == empty && stones[i][j+2]->getField() == present) ||
                    (stones[i][j]->getField() == present && stones[i][j+2]->getField() == empty)){
                    stones[i][j+1]->setField(empty);
                }
            }
                // Same Column
            else if ((stones[i][j]->getField() == empty && stones[i+2][j]->getField() == present) ||
                     (stones[i][j]->getField() == present && stones[i+2][j]->getField() == empty)){
                stones[i+1][j]->setField(empty);
            }
            else{
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size; j++){
                        stones[i][j]->isSelected = false;
                    }
                }
            }
        }
    }
}
bool Board::twoSelected() {return selectedStones == 2;}
void Board::increaseSelected() {selectedStones++;}
void Board::decreaseSelected() {selectedStones--;}
void Board::resetSelected(){selectedStones = 0;}