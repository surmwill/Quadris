#include "View.h"
#include "Subscriptions.h"
#include "BlockLib.h"
#include <iostream>

#define DEBUG 1

using namespace std;

View::View(int startLevel): level{startLevel} {
  if(DEBUG == 1) cout << "View::View" << endl;
}

View::~View() {}

SubscriptionType View::subType() {
  return SubscriptionType::Display;
}

void View::setLevel(const int level) {
  this->level = level;
}

int View::getLevel() {
  return level;
}

const BlockLib & View::getBlockLib() {
  return blockLib;
}
