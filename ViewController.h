#include <vector>
#include "Score.h"

#ifndef ViewController_h
#define ViewController_h 1

class View;

class ViewController {
 public:
  ViewController();
  void updateView();
  void showHint(const std::vector <std::vector <int>> & coords);
  void setLevel(int level);
  void restart();

 private:
  Score score;
  std::vector <unique_ptr <View>> views; //ViewController is responsible for deleting views
};

#endif
