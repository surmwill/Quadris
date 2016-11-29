#include "Score.h"
#include "SubscriptionType.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

Score::Score(int intialScore, int level, int fullObserverSize, int blockObs) currScore{intialScore}, level{level},
  fullObserverSize{minObserverSize}, blockSize{blockObs} {}

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
  currScore += (level + rows.size()) * (level + rows.size());
  currScore > highScore ? highScore = currScore;
  rows.clear();
} 

//Increases the rows cleared by 1 and checks for the entire block being cleared by comparing observers
void Score::notify(Subject &whoNotified) {
  //check for unique rows
  for(int i = 0; i < rows.size(); i++) {
    if(whoNotified.getCoords()[0] == rows[i]) break;
    else if(i == rows.size() - 1) rows.emplace_back(whoNotified.getCoords()[0]);
  }
  
  //check observers (fullObserverSize - blockObs) = (16 - 3) by default
  if(whoNotified.getObserverSize() == (fullObserverSize - blockObs)) {
    currScore += (whoNotified.getLevelCreated() + 1) * (whoNotified.getLevelCreated() + 1) + 1;
  }
}

//A multiplier to the score that changes with level
void Score::setLevel(int level) {
  this->level = level;
}

//gives a way for the views to get the level number
int Score::getLevel() {
  return level;
}

//Only notified when a row gets cleared
SubscriptionType Score::subType() {
  return SubscriptionType::Annihilation;
}
