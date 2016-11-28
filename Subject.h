#ifndef SUBJECT_H
#define SUBJECT_H 1
#include <vector>

class Observer;
class SubscriptionType;

class Subject {
 private:
  std::vector <Observer*> observers;
 public:
  void attach(Observer *o);
  void notifyObservers(SubscriptionType t);
  virtual ~Subject() = 0;
};

#endif
