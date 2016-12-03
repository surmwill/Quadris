#include "View.h"
#include "SubscriptionType.h"

View::View(int startLevel): level{startLevel} {}

View::~View() {}

void View::SubscriptionType subType() {
  return SubscriptionType::View;
}

void View::setLevel(const int level) {
  this->level = level;
}

int View::getLevel() {
  return level;
}
