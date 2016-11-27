#ifndef CELL_H
#define CELL_H 1

#include "Observer.h"
#include "Subject.h"
#include <vector>

class SubscriptionType;

class Cell: public Observer, public Subject {
 public:
  Cell(char symbol = ' ', int blockSize = 16, int levelGenerated = -1);
  void notify() override;
  void setContent(Cell *otherCell) void;
  void unsetContent();
  void detachCellObserver(Cell *toRemove);
  bool filled();
  SubscriptionType subType();
 
 private:
  std::vector <Observer*> observers;
  char symbol;
  int blockSize;
  int levelGenerated;
};

#endif
