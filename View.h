#ifndef VIEW_H
#define VIEW_H 1

#include "Observer.h"

class SubscriptionType;

class View: public Observer {
 public:
  virtual void notify() = 0;
  virtual void display(int currScore, int highScore) = 0;
  virtual SubsciptionType subType() = 0;
  virtual ~View() = 0;
 protected:
  View();
};

#endif
