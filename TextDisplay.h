#ifndef TEXT_H
#define TEXT_H 1

#include "View.h"
#include <vector>

class Score;
class Subject;

class TextDisplay: public View {
 public:
  TextDisplay(int rows = 18, int cols = 11);
  void notify(const Subject &whoNotified) override;
  void display(const Score &score) override;
  void display(const Score &score, const vector <vector <int>> & coords) override;
  void clear() override;
 private:
   std::vector <std::vector <char>> textGrid;
};

#endif
