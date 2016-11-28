#ifndef VIEW_H
#define VIEW_H 1

#include "Observer.h"
#include <vector>

class SubscriptionType;
class Subject;

class View: public Observer {
 public:
  virtual void notify(Subject &whoNotified) = 0;
  virtual void display(Score &score) = 0;
  virtual void display(Score &score, std::vector <std::vector <int>> coords) = 0;
  virtual ~View() = 0;
 protected:
  SubscriptionType subType();
  View();
};

#endif
