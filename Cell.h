#ifndef CELL_H
#define CELL_H

#include "Observer.h"
#include "Subject.h"
#include <vector>

class Cell: public Subject, public Observer {
 public:
  Cell(char symbol, int blockSize, int levelGenerated, int row = 0, int col = 0);
  void setNeighbours(Cell * left, Cell * right, Cell * top, Cell * bottom);

  // Functions to acces properties of the cell
  bool filled();
  bool lastBlockCell();
  std::vector <int> getCoords();
  char getSymbol();

  // Functions for block info movement
  bool droppable();
  bool moveableLeft();
  bool moveableRight();
  bool drop();
  void moveLeft();
  void moveRight();

  // Function for possible row annihilation
  void maybeAnnihilateRow();

  // Observer functions for block deletion
  SubscriptionType subType() const override;
  void notify(const Subject &whoNotified) override;
 
 private:
  //cell content management
  void setContent(Cell *otherCell);
  void unsetContent();

  // Functions for row annihilation
  bool checkFill(bool echoRight);
  void annihilate(bool echoRight);
  void stealInfo();

  // Observer list
  std::vector <Observer*> observers;

  // Cell data
  char symbol;
  int blockSize;
  int levelGenerated;

  // Cell coordinates
  int row;
  int col;

  // Neighbours
  Cell * leftNeighbour;
  Cell * rightNeighbour;
  Cell * topNeighbour;
  Cell * bottomNeighbour;

  // Block observer helper function
  void removeObservers(SubscriptionType t);
  void copyObservers(Cell * otherCell);
};

#endif
