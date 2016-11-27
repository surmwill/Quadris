#ifndef VIEW_H
#define VIEW_H 1

class SubscriptionType;

class View {
 public:
  virtual void notify() = 0;
  virtual void display(int currScore, int highScore) = 0;
  virtual SubsciptionType subType() = 0;
  virtual ~View();
 protected:
  View();
};
