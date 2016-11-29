#ifndef GRAPHICS_H
#define GRAPHICS_H 1

#include "View.h"
#include <vector>

class Score;
class Subject;

class GraphicsDisplay: public View {
 public:
  GraphicsDisplay(int rows = 18, int cols = 11);
  void notify(const Subject &whoNotified) override;
  void display(const Score &score) override;
  void display(const Score &score, std::vector <const std::vector <int>> & coords) override;
  void clear() override;
 private:
};

#endif
