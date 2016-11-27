#ifndef GRAPHICS_H
#define GRAPHICS_H 1

#include "View.h"
#include "Observer.h"

class SubscriptionType;

class GraphicsDisplay {
 public:
  GraphicsDisplay(int rows = 18, int cols = 11);
  void notify() override;
  void display(int score, int highScore) override;
  void SubscriptionType subType() override;
 private:
};

#endif
