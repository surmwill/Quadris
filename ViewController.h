#include <vector>
#include "Score.h"

#ifndef ViewController_h
#define ViewController_h 1

class View;

class ViewController {
 public:
  ViewController();
  void updateView(int score, int highScore);
  void updateView(std::vector <std::vector <int>>);
  void setScoreMultiplier(int multiplier);
 private:
  int getCurrentScore();
  int getHighScore();
  Score score;
  std::vector <unique_ptr <View>> views; //ViewController is responsible for deleting views
};
