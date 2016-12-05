#include "View.h"
#include "Subscriptions.h"
#include "BlockLib.h"
#include <iostream>

using namespace std;

View::View(int startLevel): level{startLevel} {}

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
