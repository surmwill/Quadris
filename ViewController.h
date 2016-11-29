#include <vector>
#include "Score.h"

#ifndef ViewController_h
#define ViewController_h 1

class View;

class ViewController {
 public:
  ViewController();
  void updateView();
  void updateView(const std::vector <std::vector <int>> & coords);
  void setLevel(int level);
 private:
  Score score;
  std::vector <unique_ptr <View>> views; //ViewController is responsible for deleting views
};

#endif
