#ifndef CELL_H
#define CELL_H 1

#include "Observer.h"
#include "Subject.h"
#include <vector>

class Cell: public Subject {
 public:
  Cell(char symbol, int blockSize, int levelGenerated, int row, int col, Cell * leftNeighbour, Cell * rightNeighbour, Cell * topNeighbour, Cell * bottomNeighbour);
  bool filled();
  std::vector <int> getCoords();

  // Functions for block info movement
  bool droppable();
  bool drop();

  // Function for possible row annihilation
  void maybeAnnihilateRow();
 
 private:
  void setContent(Cell *otherCell);
  void unsetContent();

  // Functions for row annihilation
  bool checkFill(bool echoRight);
  void annihilate(bool echoRight);
  void stealInfo();

  // Observer list
  std::vector <Observer*> observers;

  // Cell content data
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
};

#endif
