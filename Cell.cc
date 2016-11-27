#include "Observer.h"
#include "Subject.h"
#include "SubscriptionType.h"
#include <vector>

using namespace std;

Cell::Cell(char symbol, int blockSize, int levelGenerated): symbol{symbol}, blockSize{blockSize},
  levelGenerated{levelGenerated} {}

void Cell::notify(Subject &whoNotified) {
}

bool Cell::filled() {
}

vector <int> Cell::getCoords() {
}

void Cell::setContent(Cell *otherCell) {
}

void Cell::unsetContent() {
}

void Cell::detachCellObserver(Cell *toRemove) {
}

SubscriptionType Cell::subType() {
  return SubscriptionType::Cell;
}
