#ifndef SCORE_H
#define SCORE_H 1

#include "Observer.h"
#include "Subscription.h"
#include <vector>

class SubscriptionType;

class Score: public Observer {
 public:
  Score(int intialScore = 0, int level = 0, int fullObserverSize = 16, int blockObs = 3);
  void getCurrScore();
  void getHighScore();
  void updateScore();
  void notify(Subject &whoNotified) override;
  void setLevel(int level);
  SubscriptionType subType();

 private:
  int highScore;
  int currScore;
  int level;
  std::vector <int> rows;
};

#endif
