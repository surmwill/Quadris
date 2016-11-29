#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "Subscriptions.h"
class Observer;


class Subject {
  std::vector<Observer*> observers;
 public:
  void attach(Observer *o);
  void notifyObservers(SubscriptionType t);
  int getObserverSize();
  virtual ~Subject() = 0;
};

#endif
