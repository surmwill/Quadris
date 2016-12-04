#ifndef SCORE_H
#define SCORE_H 1

#include "Observer.h"
#include "Subscriptions.h"
#include <vector>

class Subject;

class Score: public Observer {
 public:
  Score(const int startLevel = 0); //intializes score with a given level
  int getCurrScore() const; //returns the current score
  int getHighScore() const; //returns the high score
  void updateScore(); //updates the current and high scores
  void notify(const Subject &whoNotified) override; //called when a cell notifies us of it's deletion
  void setLevel(const int level); //sets the level so we can adjust the score multiplier accordingly
  void clear(); //resets the current score to 0, but leaves the hi score unchanged
  SubscriptionType subType(); //returns the observer type (CellAnnihilation)

 private:
  int highScore = 0; //high score
  int currScore = 0; //current score
  int level = 0; //the level
  std::vector <int> rowsCleared; //keeps tracks of rows that have been deleted to allow additional points for the cleared rows
  void updateCurrScore(); //updates our current score, granting additional points based on the amount of rows cleared
};

#endif
