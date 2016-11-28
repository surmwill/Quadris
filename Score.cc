#include "Score.h"
#include "SubscriptionType.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

Score::Score(int intialScore, int scoreMultiplier) currScore{intialScore}, scoreMultiplier{scoreMultiplier} {}

void Score::getCurrScore() {
}

void Score::getHighScore() {
}

void Score::updateCurrScore() {
} 

void Score::notify(Subject &whoNotified) {
}

void Score::setMutliplier(int scoreMultiplier) {
  this->scoreMultiplier = scoreMultiplier;
}

SubscriptionType Score::subType() {
  return SubscriptionType::score;
}
