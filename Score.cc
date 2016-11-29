#include "Score.h"
#include "SubscriptionType.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

Score::Score(int intialScore, int scoreMultiplier, int minObserverSize) currScore{intialScore}, scoreMultiplier{scoreMultiplier},
  minObserverSize{minObserverSize} {}

//Returns the current score
int Score::getCurrScore() {
  return currScore;
}

//Returns the high score
void Score::getHighScore() {
  return highScore;
}

//Updates the current score by adding the points from clearing rows
void Score::updateCurrScore() {
  currScore += (scoreMultiplier + rowsCleared) * (scoreMultiplier + rowsCleared);
  rowsCleared = 0;
} 

//Increases the rows cleared by 1 and checks for the entire block being cleared by comparing observers
void Score::notify(Subject &whoNotified) {
  if(whoNotified.getCoords()[0] rowsCleared++;

  if(whoNotified.getObserverSize() == minObserverSize) {
    currScore += (whoNotified.getLevelCreated() + 1) * (whoNotified.getLevelCreated() + 1) + 1;
  }
}

//A multiplier to the score that changes with level
void Score::setMutliplier(int scoreMultiplier) {
  this->scoreMultiplier = scoreMultiplier;
}

//Only notified when a row gets cleared
SubscriptionType Score::subType() {
  return SubscriptionType::Annihilation;
}
