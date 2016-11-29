#include "Score.h"
#include "SubscriptionType.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

Score::Score(int intialScore, int level): currScore{intialScore}, level{level} {}

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
void Score::notify(const Subject &whoNotified) {
  //check for unique rows
  for(int i = 0; i < rows.size(); i++) {
    if(whoNotified.getCoords()[0] == rows[i]) break;
    else if(i == rows.size() - 1) rows.emplace_back(whoNotified.getCoords()[0]);
  }
  
  //checks if we are delting an entire block
  if(whoNotified.lastBlockCell()) {
    currScore += (whoNotified.getLevelCreated() + 1) * (whoNotified.getLevelCreated() + 1);
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
