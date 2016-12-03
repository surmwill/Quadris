#ifndef SCORE_H
#define SCORE_H 1

#include "Observer.h"
#include "Subscription.h"
#include <vector>

class SubscriptionType;
class Subject;

class Score: public Observer {
 public:
  int getCurrScore(); //returns the current score
  int getHighScore(); //returns the hi score
  void updateScore(); //updates the current and hi scores
  void notify(const Subject &whoNotified) override; //called when a cell notifies us of it's deletion
  void setLevel(const int level); //sets the level so we can adjust the score multiplier accordingly
  void clear(); //resets the current score to 0, but leaves the hi score unchanged
  SubscriptionType subType(); //returns the observer type (CellAnnihilation)

 private:
  int hiScore = 0; //hi score
  int currScore = 0; //current score
  int level = 0; //the level
  std::vector <int> rowsCleared; //keeps tracks of rows that have been deleted to allow additional points for the cleared rows
};

#endif
