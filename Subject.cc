#include "Subject.h"
#include "Observer.h"
#include "Subscriptions.h"
#include "Cell.h"
#include <vector>

using namespace std;

Subject::~Subject(){}

void Subject::attach(Observer * o) { observers.emplace_back(o); }

void Subject::notifyObservers(SubscriptionType t) {
  for (auto &o: observers) {
    if (o->subType() == t) o->notify(*this);
  }
}

int Subject::getObserverSize() {
  return observers.size();
}
