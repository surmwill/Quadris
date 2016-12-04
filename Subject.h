#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <vector>
#include "Subscriptions.h"
#include "Info.h"

class Observer;

class Subject {
  std::vector<Observer*> observers; //the last of observers for a subject

 public:
  void attach(Observer * o); //attaches observer o to the observer list
  void notifyObservers(SubscriptionType t); //notifies all observers in the list with SubscriptionType t
  int getObserverSize(); //returns the number of observers
  void removeObservers(SubscriptionType t); // remove observers of a specific subscription type
  void copyObservers(Subject * otherSubject); // take the observers from another subject
  virtual const Info & getInfo() const = 0; //returns information about the Subject
  virtual ~Subject() = 0;
};

#endif
