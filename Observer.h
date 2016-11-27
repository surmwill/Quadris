#ifndef OBSERVER_H
#define OBSERVER_H 1

class Observer {
  public:
   virtual void notify(Subject &whoNotified) = 0; //pass the cell that notified
   virtual void SubscriptionType subType() = 0;
   virtual ~Observer() = deafult;
};
#endif
