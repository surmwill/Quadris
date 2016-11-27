#include "Observer.h"
#include "Subscription.h"

class SubscriptionType;

class Score {
 public: 
  Score(int intialScore = 0);
  void getCurrScore();
  void getHighScore();
  void updateScore();
  void notfiy() override;
  SubscriptionType subType();
 private:
  int highScore;
  int currScore;
  int rowsCleared;
};

