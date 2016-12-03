#include <vector>
#include "Score.h"

#ifndef ViewController_h
#define ViewController_h 1

class View;

class ViewController {
 public:
  ViewController(int startLevel = 0, const bool textOnly = false); //constructs a TextView and (optionally) GraphicsView
  void updateView(); //updates the views with the latest score and level information 
  void showHint(const std::vector <std::vector <int>> & coords); //sends grid coordinates to the Views in order to draw the hint loction
  void setLevel(const int level); //sets the level of the both views and the score
  void restart(); //clears the board, and resets the current score to 0

 private:
  Score score; //information about various scores of the game, sent to both Views
  std::vector <unique_ptr <View>> views; //An array of the various Views we have
};

#endif
