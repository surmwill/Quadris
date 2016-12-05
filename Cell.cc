#include <vector>
#include "Observer.h"
#include "Subject.h"
#include "Subscriptions.h"
#include "Cell.h"
#include "Info.h"
#include <iostream>

#define DEBUG 1

using namespace std;

Cell::Cell(char symbol, int blockSize, int levelGenerated, int row, int col): cellInfo{symbol, blockSize, levelGenerated, row, col} {
  leftNeighbour = nullptr;
  rightNeighbour = nullptr;
  topNeighbour = nullptr;
  bottomNeighbour = nullptr;

  if(DEBUG == 1) cout << "Cell::Cell()" << endl;
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

bool Cell::filled() {return cellInfo.symbol != ' ';}

const Info & Cell::getInfo() const {
  return cellInfo;
}

bool Cell::movableLeft(){
  if (DEBUG == 1) cout << "Cell::movableLeft()" << endl;
  if (DEBUG == 1) cout << "Left Neighbour" << ((leftNeighbour == nullptr) ? "nullptr" : "Cell") << endl;

  // check to see if the cell to the left is empty
  return (leftNeighbour != nullptr) && !(leftNeighbour->filled());
}

bool Cell::movableRight(){
  if (DEBUG == 1) cout << "Cell::movableRight()" << endl;
  if (DEBUG == 1) cout << "Right Neighbour" << ((rightNeighbour == nullptr) ? "nullptr" : "Cell") << endl;

  // check to see if the cell to the right is empty
  return (rightNeighbour != nullptr) && !(rightNeighbour->filled());
}

bool Cell::droppable(){
  if (DEBUG == 1) cout << "Cell::droppable()" << endl;
  if (DEBUG == 1) cout << "Bottom Neighbour" << ((bottomNeighbour == nullptr) ? "nullptr" : "Cell") << endl;

  // check to see if the below cell is empty
  return (bottomNeighbour != nullptr) && !(bottomNeighbour->filled());
}

Cell * Cell::drop(){
  if (DEBUG == 1) cout << "Cell::drop()" << endl;

  //give the bottomNeighbour this cell's info. Unset this cell.
  if (bottomNeighbour != nullptr) bottomNeighbour->setContent(this);
  unsetContent();

  return bottomNeighbour;
}

Cell * Cell::moveLeft(){
  if (DEBUG == 1) cout << "Cell::moveLeft()" << endl;

  //give the leftNeighbour this cell's info. Unset this cell.
  if (leftNeighbour != nullptr) leftNeighbour->setContent(this);
  unsetContent();

  return leftNeighbour;
}

Cell * Cell::moveRight(){
  if (DEBUG == 1) cout << "Cell::moveRight()" << endl;

  //give the rightNeighbour this cell's info. Unset this cell.
  if (rightNeighbour != nullptr) rightNeighbour->setContent(this);
  unsetContent();

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

void Cell::setContent(Cell *otherCell) {
  // steal the content of otherCell
  cellInfo.symbol = otherCell->cellInfo.symbol;
  cellInfo.blockSize = otherCell->cellInfo.blockSize;
  cellInfo.levelGenerated = otherCell->cellInfo.levelGenerated;
  notifyObservers(SubscriptionType::Display);
}

void Cell::unsetContent() {
  cellInfo.symbol = ' ';
  removeObservers(SubscriptionType::Cell);
  notifyObservers(SubscriptionType::Display);
}
