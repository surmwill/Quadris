#ifndef CELL_H
#define CELL_H 1

#include "Observer.h"
#include "Subject.h"
#include <vector>

class SubscriptionType;

class Cell: public Observer, public Subject {
 public:
  Cell(char symbol = ' ', int blockSize = 16, int levelGenerated = -1);
  void notify(Subject &whoNotified) override;
  bool filled();
  std::vector <int> getCoords();
  SubscriptionType subType();
 
 private:
  void setContent(Cell *otherCell); //only called when notified
  void detachCellObserver(Cell *toRemove); //only called when notified
  void unsetContent(); //only called when notified
  std::vector <Observer*> observers;
  char symbol;
  int blockSize;
  int levelGenerated;
};

#endif
