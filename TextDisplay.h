#ifndef TEXT_H
#define TEXT_H 1

#include "View.h"
#include <vector>

class Score;

class TextDisplay: public View {
 public:
  TextDisplay(int rows = 18, int cols = 11);
  void notify() override;
  void display(Score &score) override;
  void display(Score &score, vector <vector <int>> coords) override;
 private:
   std::vector <std::vector <char>> textGrid;
};

#endif
