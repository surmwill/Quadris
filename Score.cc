#include "Score.h"
#include "SubscriptionType.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

int Score::getCurrScore() {
  return currScore;
}

void Score::getHighScore() {
  return highScore;
}

void Score::updateCurrScore() {
  currScore += (level + rowsCleared.size()) * (level + rowsCleared.size());
  currScore > highScore ? highScore = currScore;
  rowsCleared.clear(); //clears the amount of rows cleared
} 

void Score::notify(const Subject &whoNotified) {
  //check for unique rows, increase the amount of rows cleared if a unqiue row is found
  for(int i = 0; i < rowsCleared.size(); i++) {
    int cellRow = whoNotified.getCoords()[0];

    if(cellRow == rows[i]) break;
    else if(i == rows.size() - 1) rowsCleared.emplace_back(cellRow);
  }
  
  //checks if we are deleting an entire block
  if(whoNotified.lastBlockCell()) {
    currScore += (whoNotified.getLevelCreated() + 1) * (whoNotified.getLevelCreated() + 1);
  }
}

void Score::setLevel(const int level) {
  this->level = level;
}

int Score::getLevel() {
  return level;
}

void Score::clear() {
  currScore = 0;
  rowsCleared.clear(); //cleared as to not affect the next score update
}

SubscriptionType Score::subType() {
  return SubscriptionType::Annihilation;
}
