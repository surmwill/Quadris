#include "Score.h"
#include "SubscriptionType.h"

using namespace std;

Score::Score(int intialScore) currScore{intialScore} {}

void Score::getCurrScore() {
}

void Score::getHighScore() {
}

void Score::updateCurrScore() {
} 

void Score::notify() {
}

SubscriptionType Score::subType() {
  return SubscriptionType::score;
}
