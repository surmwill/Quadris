#ifndef GRAPHICS_H
#define GRAPHICS_H 1

#include "View.h"
#include <vector>

class Score;

class GraphicsDisplay: public View {
 public:
  GraphicsDisplay(int rows = 18, int cols = 11);
  void notify() override;
  void display(Score &score) override;
  void display(Score &score, std::vector <std::vector <int>> coords) override;
 private:
};

#endif
