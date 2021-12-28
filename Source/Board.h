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
    std::vector<std::vector<std::unique_ptr<Stone>>> stones;
    void initBoard();
    void makeMove();
    void resetSelections();

private:
    const int size = SIZE;
};

