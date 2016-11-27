#include "View.h"
#include "Observer.h"

class SubscriptionType;

class GraphicsDisplay {
 public:
  GraphicsDisplay();
  void notify() override;
  void display(int score, int highScore) override;
  void SubscriptionType subType() override;
 private:
};
