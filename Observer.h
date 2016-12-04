#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include "Subscriptions.h"

class Subject;
class Cell;

class Observer {
 public:
  virtual void notify(const Subject &whoNotified) = 0;  // passes the Cell which called the notify method
  virtual SubscriptionType subType() = 0; //The subscription type of an observer
  virtual ~Observer() = default;
};
#endif
