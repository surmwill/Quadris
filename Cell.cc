#include "Observer.h"
#include "Subject.h"
#include "SubscriptionType.h"

using namespace std;

Cell::Cell(char symbol, int blockSize, int levelGenerated): symbol{symbol}, blockSize{blockSize},
  levelGenerated{levelGenerated} {}

void Cell::notify() {
}

void Cell::setContent(Cell *otherCell) {
}

void Cell::unsetContent() {
}

void Cell::detachCellObserver(Cell *toRemove) {
}

bool Cell::filled() {
}

SubscriptionType Cell::subType() {
  return SubscriptionType::Cell;
}
