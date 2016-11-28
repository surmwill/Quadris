#include "Subject.h"
#include "SubscriptionType.h"
#include "Observer.h"
#include <vector>

using namespace std;

Subject::~Subject();

void Subject::attach(Observer *o) {
  observers.emplace_back(o);
}

void Subject::notifyObservers(SubscriptionType t) {
  for(auto obs:observers) {
    if((*obs[i])->subType() == t) (*obs[i])->notify(*this);
  }
}
