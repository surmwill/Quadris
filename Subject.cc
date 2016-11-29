#include "Subject.h"
#include "Observer.h"
#include "Subscriptions.h"
#include "Cell.h"

#include <iostream>

using namespace std;

Subject::~Subject(){}

void Subject::attach(Observer *o) { observers.push_back(o); }

void Subject::notifyObservers(SubscriptionType t) {
  for (Observer * o: observers){
    if (o->subType() == t){
      o->notify(*this);
    }
  }
}

int Subject::getObserverSize() {
  return observers.size();
}
