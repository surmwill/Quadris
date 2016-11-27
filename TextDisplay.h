#ifndef TEXT_H
#define TEXT_H 1

#include "View.h"
#include "Observer.h"
#include <vector>

class SubscriptionType;

class TextDisplay {
 public:
  TextDisplay();
  void notify() override;
  void display(int score, int highScore) override;
  void SubscriptionType subType() override;
 private:
   std::vector <char> grid;
};

#endif
