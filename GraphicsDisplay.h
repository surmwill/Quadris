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
  GraphicsDisplay(int rows = 18, int cols = 11);
  void notify(const Subject &whoNotified) override; //Cell's notify the board whenever they change state, so we can update the cells accordingly
  void display(const Score &score) override; //displays the board, calling both drawTop() and drawMiddle()
  void display(const Score &score, const std::vector <const std::vector <int>> & coords) override; //displays the hint, only calling drawMiddle()
  void clear() override; //clears the board and redraws the curr score

 private:
   int rows; //rows of cells we want
   int cols; //cols of cells we want
   int cellWidth = 40; //the width in pixels of a cell in the display
   int cellHeight = 40; //the height in pixels of a cell in the display
   int topSpace = 60; //space reserved for the drawTop() function
   int totalLength; //the total length in pixels of the window
   int totalHeight; //the total height in pixels of the window
   Xwindow win; //the Xwindow object that allows us to display amd update graphics
   std::map <char, Xwindow> symToColour; //maps a char symbol key to an Xwindow::Color
   
   Xwindow symbolToColour(char symbol); //Accesses the map with additional error checking
   void drawTop(int score, int highScore, int level); //displays, score, level, and next block
   void fillCell(int row, int col, Xwindow colour); //fills the cell at (row,col) with colour
};

#endif
