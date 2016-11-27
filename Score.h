#ifndef SCORE_H
#define SCORE_H 1

#include "Observer.h"
#include "Subscription.h"

class SubscriptionType;

class Score: public Observer {
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

#endif
