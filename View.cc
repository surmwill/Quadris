#include "View.h"
#include "Subscriptions.h"
#include "BlockLib.h"

View::View(int startLevel): level{startLevel} {}

View::~View() {}

SubscriptionType View::SubscriptionType subType() {
  return SubscriptionType::Display;
}

void View::setLevel(const int level) {
  this->level = level;
}

int View::getLevel() {
  return level;
}

const BlockLib & getBlockLib() {
  return blockLib;
}
