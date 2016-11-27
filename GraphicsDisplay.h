#ifndef GRAPHICS_H
#define GRAPHICS_H 1

#include "View.h"

class Score;
class SubscriptionType;

class GraphicsDisplay: public View {
 public:
  GraphicsDisplay(int rows = 18, int cols = 11);
  void notify() override;
  void display(Score &score) override;
  void SubscriptionType subType() override;
 private:
};

#endif
