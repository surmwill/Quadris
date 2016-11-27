#include "View.h"
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
