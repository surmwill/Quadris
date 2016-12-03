#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <vector>
#include "Subscriptions.h"

class Observer;

class Subject {
  std::vector<Observer*> observers; //the last of observers for a subject

 public:
  void attach(const Observer *const o); //attaches observer o to the observer list
  void notifyObservers(SubscriptionType t); //notifies all observers in the list with SubscriptionType t
  int getObserverSize(); //returns the number of observers
  virtual ~Subject() = 0;
};

#endif
