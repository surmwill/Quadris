#include <cmath>
#include "Score.h"
#include "Subscriptions.h"
#include "Observer.h"
#include "Subject.h"
#include "Info.h"
#include <iostream>

using namespace std;

Score::Score(const int startLevel): level{startLevel} {}

int Score::getCurrScore() const {
  return currScore;
}

int Score::getHighScore() const {
  return highScore;
}

void Score::updateCurrScore() {
  cout << "score updated" << endl;
  cout << "num rows cleared: " << rowsCleared.size() << endl;
  if(rowsCleared.size() < 1) return;

  currScore += (level + rowsCleared.size()) * (level + rowsCleared.size());
  if(currScore > highScore) highScore = currScore;
  rowsCleared.clear(); //resets the amount of rows cleared
  cout << "curr score: " << currScore << endl;
} 

void Score::notify(const Subject &whoNotified) {
  unsigned int i = 0;
  int cellRow = whoNotified.getInfo().row;

  cout << "score notified" << endl;
  //check for unique rows, increase the amount of rows cleared if a unqiue row is found
  for(i = 0; i < rowsCleared.size(); i++) {
    if(cellRow == rowsCleared[i]) break;
  }

  if(i == rowsCleared.size()) rowsCleared.emplace_back(cellRow);
  cout << "blockSize: " << whoNotified.getInfo().blockSize;
  //cout << "num rows cleared: " << rowsCleared.size() << endl;
  //checks if we are deleting the last Cell of a block
  if(whoNotified.getInfo().blockSize == 0) {
    cout << "block size is 1" << endl;
    currScore += pow((whoNotified.getInfo().levelGenerated + 1), 2);
  }
}

void Score::setLevel(const int level) {
  this->level = level;
}

void Score::clear() {
  cout << "cleared" << endl;
  currScore = 0;
  rowsCleared.clear(); //cleared as to not affect the next score update
}

SubscriptionType Score::subType() {
  return SubscriptionType::Annihilation;
}
