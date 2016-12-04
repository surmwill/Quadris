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

void Subject::removeObservers(SubscriptionType t){
  for (unsigned int i = 0; i < observers.size(); i++){
    if (observers[i]->subType() == t){
      observers.erase(observers.begin()+i);
    }
  }
}

void Subject::copyObservers(Subject * otherSubject){
  // clear current observers
  observers.erase(observers.begin(), observers.end());

  // take all otherCell's observers
  for (Observer *o: otherSubject.observers){
    attach(o);
  }
}
