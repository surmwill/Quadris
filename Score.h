#ifndef SCORE_H
#define SCORE_H 1

#include "Observer.h"
#include "Subscription.h"
#include <vector>

class SubscriptionType;

class Score: public Observer {
 public:
  Score(int intialScore = 0, int scoreMultiplier = 0, int fullObserverSize = 16, int blockObs = 3);
  void getCurrScore();
  void getHighScore();
  void updateScore();
  void notify(Subject &whoNotified) override;
  void setMultiplier(int scoreMultiplier);
  SubscriptionType subType();

 private:
  int highScore;
  int currScore;
  int scoreMultiplier;
  std::vector <int> rows;
};

#endif
