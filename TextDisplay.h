#ifndef TEXT_H
#define TEXT_H 1

#include "View.h"
#include <vector>

class Score;
class Subject;

class TextDisplay: public View {
 public:
  TextDisplay(const int startLevel = 0, const int rows = 18, const int cols = 11); //intrializes the TextDisplay's grid with given dimensions, and its starting level
  void notify(const Subject &whoNotified) override;
  void display(const Score &score) override;
  void showHint(const std::vector <std::vector <int>> & coords) override;
  void clear() override;

 private:
  void printDashes(const int numDashes); //prints dashes on the screen ------------
  std::vector <std::vector <char>> textGrid; //stores the characters that made up the grid
  std::vector <std::vector <char>> nextBlock; //stores the characters that make up the next block
};

#endif
