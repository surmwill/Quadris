#include <vector>
#include "Observer.h"
#include "Subject.h"
#include "Subscriptions.h"
#include "Cell.h"
#include "Info.h"

using namespace std;

Cell::Cell(char symbol, int blockSize, int levelGenerated, int row, int col): symbol{symbol}, blockSize{blockSize},
  levelGenerated{levelGenerated}, row{row}, col{col} {

  leftNeighbour = nullptr;
  rightNeighbour = nullptr;
  topNeighbour = nullptr;
  bottomNeighbour = nullptr;
}

void Cell::setNeighbours(Cell * left, Cell * right, Cell * top, Cell * bottom){
  leftNeighbour = left;
  rightNeighbour = right;
  topNeighbour = top;
  bottomNeighbour = bottom;
}

bool Cell::filled() {return symbol != ' ';}

Info & Cell::getInfo() const {
  cellInfo.coords.push_back(row);
  cellInfo.coords.push_back(col);
  return &cellInfo;
}

bool Cell::movableLeft(){
  return leftNeighbour->filled();
}

bool Cell::movableRight(){
  return rightNeighbour->filled();
}

bool Cell::droppable(){
  return bottomNeighbour->filled();
}

// any idea why this is bool?
bool Cell::drop(){
  //give the bottomNeighbour this cell's info. Unset this cell.
  bottomNeighbour->setContent(this);
  unsetContent();
}

void Cell::moveLeft(){
  //give the leftNeighbour this cell's info. Unset this cell.
  leftNeighbour->setContent(this);
  unsetContent();
}

void Cell::moveRight(){
  //give the rightNeighbour this cell's info. Unset this cell.
  rightNeighbour->setContent(this);
  unsetContent();
}

SubscriptionType Cell::subType() const{
  return SubscriptionType::Cell;
}

void Cell::notify(const Subject &whoNotified){
  blockSize--;
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
  cellInfo.symbol = otherCell->symbol;
  cellInfo.blockSize = otherCell->blockSize;
  cellInfo.levelGenerated = otherCell->levelGenerated;
  notifyObservers(SubscriptionType::Display);
}

void Cell::unsetContent() {
  cellInfo.symbol = ' ';
  removeObservers(SubscriptionType::Cell);
  notifyObservers(SubscriptionType::Display);
}

void Cell::removeObservers(SubscriptionType t){
  for (unsigned int i = 0; i < observers.size(); i++){
    if (observers[i]->subType() == SubscriptionType::Cell){
      observers.erase(observers.begin()+i);
    }
  }
}

void Cell::copyObservers(Cell * otherCell){
  // clear current observers
  observers.erase(observers.begin(), observers.end());

  // take all otherCell's observers
  for (Observer *o: observers){
    attach(o);
  }
}

