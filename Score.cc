#include <cmath>
#include "Score.h"
#include "Subscriptions.h"
#include "Observer.h"
#include "Subject.h"
#include "Info.h"
#include <iostream>

#define DEBUG 1

using namespace std;

Score::Score(const int startLevel): level{startLevel} {
  if(DEBUG == 1) cout << "Score::Score" << endl;
}

int Score::getCurrScore() const {
  return currScore;
}

int Score::getHighScore() const {
  return highScore;
}

void Score::updateCurrScore() {
  currScore += (level + rowsCleared.size()) * (level + rowsCleared.size());
  if(currScore > highScore) highScore = currScore;
  rowsCleared.clear(); //resets the amount of rows cleared
} 

void Score::notify(const Subject &whoNotified) {
  //check for unique rows, increase the amount of rows cleared if a unqiue row is found
  for(unsigned int i = 0; i < rowsCleared.size(); i++) {
    int cellRow = whoNotified.getInfo().coords[0];

    if(cellRow == rowsCleared[i]) return;
    else if(i == rowsCleared.size() - 1) rowsCleared.emplace_back(cellRow);
  }
  
  //checks if we are deleting the last Cell of a block
  if(whoNotified.getInfo().blockSize == 1) {
    currScore += pow((whoNotified.getInfo().levelGenerated + 1), 2);
  }
}

void Score::setLevel(const int level) {
  this->level = level;
}

void Score::clear() {
  currScore = 0;
  rowsCleared.clear(); //cleared as to not affect the next score update
}

SubscriptionType Score::subType() {
  return SubscriptionType::Annihilation;
}
