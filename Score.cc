#include "Score.h"
#include "SubscriptionType.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

Score::Score(int intialScore, int scoreMultiplier) currScore{intialScore}, scoreMultiplier{scoreMultiplier} {}

int Score::getCurrScore() {
  return currScore;
}

void Score::getHighScore() {
  return highScore;
}

void Score::updateCurrScore() {
} 

void Score::notify(Subject &whoNotified) {
  int minObserverSize = 2;

  
  if(whoNotified.observerSize() == minObserverSize) {
    score += (whoNotified.getLevelCreated() + 1) * (whoNotified.getLevelCreated() + 1) + 1;
  }

}

void Score::setMutliplier(int scoreMultiplier) {
  this->scoreMultiplier = scoreMultiplier;
}

SubscriptionType Score::subType() {
  return SubscriptionType::score;
}
