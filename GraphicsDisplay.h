#ifndef GRAPHICS_H
#define GRAPHICS_H 1

#include "View.h"
#include <vector>
#include <map>

class Score;
class Subject;

class GraphicsDisplay: public View {
 public:
  GraphicsDisplay(int rows = 18, int cols = 11);
  void notify(const Subject &whoNotified) override; //Cell's notify the board whenever they change state, so we can update the cells accordingly
  void display(const Score &score) override; //displays the board, calling both drawTop() and drawMiddle()
  void display(const Score &score, std::vector <const std::vector <int>> & coords) override; //displays the hint, only calling drawMiddle()
  void clear() override; //clears the board and redraws the curr score

 private:
   int rows; //rows of cells we want
   int cols; //cols of cells we want
   int cellWidth; //the width in pixels of a cell in the display
   int cellHeight; //the height in pixels of a cell in the display
   int topSpace; //space reserved for the drawTop() function
   int totalLength; //the total length in pixels of the window
   int totalHeight; //the total height in pixels of the window

   Xwindow symbolToColour(char symbol); //returns a colour based on symbol
   void drawTop(); //displays, score, level, and next block
   void drawMiddle(); //displays the grid
};

#endif
