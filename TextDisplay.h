#ifndef TEXT_H
#define TEXT_H 1

#include "View.h"
#include "BlockLib.h"
#include <vector>

class Score;
class Subject;

class TextDisplay: public View {
 public:
  TextDisplay(int startLevel = 0, int rows = 18, int cols = 11);
  void notify(const Subject &whoNotified) override;
  void display(const Score &score) override;
  void showHint(const vector <vector <int>> & coords) override;
  void clear() override;
  void setLevel(const int level) override;

 private:
  int level;
  void printDashes(int numDashes);
  std::vector <std::vector <char>> textGrid;
  std::vector <std::vector <char>> nextBlock;
  BlockLib blockLib;
};

#endif
