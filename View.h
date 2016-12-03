#ifndef VIEW_H
#define VIEW_H 1

#include "Observer.h"
#include <vector>

class SubscriptionType;
class Subject;

class View: public Observer {
 public:
  virtual void notify(const Subject &whoNotified) = 0;
  virtual void display(const Score &score) = 0;
  virtual void showHint(const std::vector <std::vector <int>> & coords) = 0;
  virtual void clear() = 0;
  virtual void setLevel(const int level) = 0;
  virtual ~View() = 0;
  void setLevel(const int level);

 protected:
  SubscriptionType subType();
  int getLevel();
  View(int startLevel = 0);

 private:
  int level;
};

#endif
