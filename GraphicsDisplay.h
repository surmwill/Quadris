#ifndef GRAPHICS_H
#define GRAPHICS_H 1

#include "View.h"
#include "Window.h"
#include <vector>
#include <map>

class Score;
class Subject;

class GraphicsDisplay: public View {
 public:
  GraphicsDisplay(const int startLevel = 0, const int rows = 18, const int cols = 11); //initializes the graphics display with a grid of size (row, col) and a starting level
  void notify(const Subject &whoNotified) override; 
  void display(const Score &score) override; 
  void showHint(const std::vector <std::vector <int>> & coords) override; 
  void clear() override; 

 private:
   int rows; //rows of cells we want for the grid
   int cols; //cols of cells we want for the grid
   int cellWidth = 40; //the width in pixels of a cell in the display
   int cellHeight = 40; //the height in pixels of a cell in the display
   int topSpace = 60; //space reserved for the top portion of the screen(displays level, score, hi score, next block)
   int totalLength; //the total length in pixels of the window
   int totalHeight; //the total height in pixels of the window
   int clearColour = Xwindow::White; //the colour of a clear portion of the board
   Xwindow win; //the Xwindow object that allows us to display and update graphics
   std::map <char, int> symToColour; //maps a char symbol key to an Xwindow::Color
   int symbolToColour(const char symbol); //Returns the Xwindow colour correspoinding to the symbol, black otherwise
   void fillCell(const int row, const int col, int colour); //fills the cell at (row,col) with colour
   void drawNextBlock(const std::vector <std::vector <char>> & layout, int colour); //draws the next block portion of our board
};

#endif
