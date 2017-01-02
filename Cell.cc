#include <vector>
#include "Observer.h"
#include "Subject.h"
#include "Subscriptions.h"
#include "Cell.h"
#include "Info.h"
#include <iostream>

using namespace std;

Cell::Cell(char symbol, int blockSize, int levelGenerated, int row, int col): cellInfo{symbol, blockSize, levelGenerated, row, col} {
  leftNeighbour = nullptr;
  rightNeighbour = nullptr;
  topNeighbour = nullptr;
  bottomNeighbour = nullptr;
}

void Cell::setNeighbours(Cell * left, Cell * right, Cell * top, Cell * bottom){
  // set pointers to adjacent cells
  leftNeighbour = left;
  rightNeighbour = right;
  topNeighbour = top;
  bottomNeighbour = bottom;
}

void Cell::setSymbol(const char symbol) {
  // change the cell's symbol
  cellInfo.symbol = symbol;
  notifyObservers(SubscriptionType::Display); 
}

void Cell::setRow(const int row) {
  cellInfo.row = row;
}

void Cell::setCol(const int col) {
  cellInfo.col = col;
}

bool Cell::filled() {return cellInfo.symbol != ' ';}

const Info & Cell::getInfo() const {
  return cellInfo;
}

bool Cell::movableLeft(){
  // check to see if the cell to the left is empty
  return (leftNeighbour != nullptr) && !(leftNeighbour->filled());
}

bool Cell::movableRight(){
  // check to see if the cell to the right is empty
  return (rightNeighbour != nullptr) && !(rightNeighbour->filled());
}

bool Cell::droppable(){
  // check to see if the below cell is empty
  return (bottomNeighbour != nullptr) && !(bottomNeighbour->filled());
}

Cell * Cell::drop(){
  // give the bottomNeighbour this cell's info. Unset this cell.
  if ((filled()) && (!(cellInfo.set))) bottomNeighbour->setContent(this);
  if (!(filled() && cellInfo.set)) unsetContent();
  return bottomNeighbour;
}

Cell * Cell::moveLeft(){
  // give the leftNeighbour this cell's info. Unset this cell.
  if ((filled()) && (!(cellInfo.set))) leftNeighbour->setContent(this);
  if (!(filled() && cellInfo.set)) unsetContent();
  return leftNeighbour;
}

Cell * Cell::moveRight(){
  // give the rightNeighbour this cell's info. Unset this cell.
  if ((filled()) && (!(cellInfo.set))) rightNeighbour->setContent(this);
  if (!(filled() && cellInfo.set))unsetContent();
  return rightNeighbour;
}

SubscriptionType Cell::subType(){
  return SubscriptionType::Cell;
}

void Cell::notify(const Subject &whoNotified){
  cellInfo.blockSize--;
}

void Cell::maybeAnnihilateRow(){
  // if row is filled, annihilate
  if (checkFill(true) && checkFill(false)){
    annihilate(true);
    annihilate(false);
    stealInfo();
  }
}

bool Cell::checkFill(bool echoRight){
  // recursively check self and all right or left neighbours for fill
  Cell * targetCell = (echoRight ? rightNeighbour : leftNeighbour);
  return (filled() && ((targetCell == nullptr) || targetCell->checkFill(echoRight)));
}

void Cell::annihilate(bool echoRight){
  // recursively annihilate either left or right neighbours
  Cell * targetCell = (echoRight ? rightNeighbour: leftNeighbour);
  if (targetCell != nullptr){
    cellInfo.blockSize--;
    notifyObservers(SubscriptionType::Annihilation);
    notifyObservers(SubscriptionType::Cell);
    targetCell->annihilate(echoRight);
    targetCell->stealInfo();
  }
}

void Cell::stealInfo(){
  if (topNeighbour != nullptr){
    // recursively steal the info of the above Cell
    setContent(topNeighbour);
    topNeighbour->stealInfo();
  } else {
    // unset info if there is nothing to steal
    unsetContent();
  }
}

void Cell::setNeighbours(Cell *otherCell) {
  leftNeighbour = otherCell->leftNeighbour;
  rightNeighbour = otherCell->rightNeighbour;
  topNeighbour = otherCell->topNeighbour;
  bottomNeighbour = otherCell->bottomNeighbour;
}

void Cell::setContent(Cell *otherCell) {
  // steal the content of otherCell
  cellInfo.symbol = otherCell->cellInfo.symbol;
  cellInfo.blockSize = otherCell->cellInfo.blockSize;
  cellInfo.levelGenerated = otherCell->cellInfo.levelGenerated;
  cellInfo.set = otherCell->cellInfo.set;
  notifyObservers(SubscriptionType::Display);
}

void Cell::unsetContent() {
  cellInfo.symbol = ' ';
  removeObservers(SubscriptionType::Cell);
  notifyObservers(SubscriptionType::Display);
}

void Cell::setInPlace() {
  cellInfo.set = true;
  maybeAnnihilateRow();
}
