#include "View.h"
#include "SubscriptionType.h"
#include "BlockLib.h"

View::View(int startLevel): level{startLevel} {}

View::~View() {}

SubscriptionType View::SubscriptionType subType() {
  return SubscriptionType::View;
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
