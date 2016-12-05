#ifndef CELL_H
#define CELL_H

#include "Observer.h"
#include "Subject.h"
#include "Info.h"
#include <vector>

class Cell: public Subject, public Observer {
 public:
  Cell(char symbol, int blockSize, int levelGenerated, int row = 0, int col = 0);
  void setNeighbours(Cell * left, Cell * right, Cell * top, Cell * bottom);

  // Functions to acces properties of the cell
  bool filled(); //not needed by View or Score. needed elsewhere?
  const Info & getInfo() const override;

  void setSymbol(const char symbol); //sets the cell character to symbol

  // Functions for block info movement
  bool droppable();
  bool movableLeft();
  bool movableRight();
  Cell * drop(); // returns a pointer to the new location of the cell info
  Cell * moveLeft(); // returns a pointer to the new location of the cell info
  Cell * moveRight();// returns a pointer to the new location of the cell info

  // Function for possible row annihilation
  void maybeAnnihilateRow();

  // Observer functions for block deletion
  SubscriptionType subType() override;
  void notify(const Subject &whoNotified) override;
 
  //cell content management
  void setContent(Cell *otherCell);
  void unsetContent();
  void setInPlace();

 private:
  // Cell Data
  Info cellInfo;

  // Functions for row annihilation
  bool checkFill(bool echoRight);
  void annihilate(bool echoRight);
  void stealInfo();

  // Neighbours
  Cell * leftNeighbour;
  Cell * rightNeighbour;
  Cell * topNeighbour;
  Cell * bottomNeighbour;
};

#endif
