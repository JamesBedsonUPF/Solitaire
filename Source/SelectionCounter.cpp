#include "SelectionCounter.h"

SelectionCounter::SelectionCounter() {selectedStones = 0;}
SelectionCounter::~SelectionCounter() = default;
void SelectionCounter::decreaseSelected() {selectedStones--;}
void SelectionCounter::increaseSelected() {selectedStones++;}
void SelectionCounter::resetSelected() {selectedStones = 0;}
bool SelectionCounter::twoSelected() {return selectedStones == 2;}