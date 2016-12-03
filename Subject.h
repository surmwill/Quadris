#ifndef SUBJECT_H
#define SUBJECT_H 1
#include <vector>

class Observer;
class SubscriptionType;

class Subject {
 private:
  std::vector <Observer*> observers; //the list of observers

 public:
  void attach(const Observer *const o); //attaches an observer o
  void notifyObservers(SubscriptionType t); //notifys all the observers in the list
  virtual ~Subject() = 0;
};

#endif
