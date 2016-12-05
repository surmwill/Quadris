#include "Subscriptions.h"
#include "GraphicsDisplay.h"
#include "Score.h"
#include "View.h"
#include "Subject.h"
#include "Window.h"
#include "BlockLib.h"
#include "Info.h"
#include <map>
#include <vector>
#include <iostream>

#define DEBUG 1 

using namespace std;

GraphicsDisplay::GraphicsDisplay(const int startLevel, const int rows, const int cols): View{startLevel}, rows{rows}, cols{cols}, totalLength{cols * cellWidth}, 
  totalHeight{(rows * cellHeight) + topSpace}, win{totalLength, totalHeight} {
  symToColour.emplace(' ', Xwindow::White);
  symToColour.emplace('I', Xwindow::Magenta); 
  symToColour.emplace('J', Xwindow::Red);
  symToColour.emplace('L', Xwindow::Green);
  symToColour.emplace('O', Xwindow::Cyan);
  symToColour.emplace('D', Xwindow::Brown);
  symToColour.emplace('Z', Xwindow::Orange);
  symToColour.emplace('T', Xwindow::Blue);

  clear();

  if(DEBUG == 1) cout << "GraphicsDisplay::GraphicsDisplay()" << endl;
}

//Fill the cell that notified the display
void GraphicsDisplay::notify(const Subject &whoNotified) {
  int row = whoNotified.getInfo().row;
  int col = whoNotified.getInfo().col;
  bool specialCell = false;
  
  //If the row and column of the cell are not initialized (coords are -1, -1) the special cell is notifying us of our next block
  if(row == -1 && col == -1) specialCell = true;

  char cellSymbol = whoNotified.getInfo().symbol; //the Cell's symbol

  if(specialCell) drawNextBlock(getBlockLib().getBlockLayout(cellSymbol), symbolToColour(cellSymbol)); //if its a special cell draw the next block
  else fillCell(row, col, symbolToColour(cellSymbol)); //otherwise draw in the corresponding cell in the grid
}

//Draws the top section of the board. The grid is drawn through notifications
void GraphicsDisplay::display(const Score &score) {
  int ySpacing = 10; //the Y spacing between the texts of level, score, highscore along with the spacing between level,and the top of the screen
  int xIndent = 5; //the X indent from the left side of the screen for level, score, and highscore text
  int valuexIndent = 80; //Indent from each of the texts to their associated value (ex highscore:      10)
  int nextBlockIndent = (totalLength / 2) - 50; //Indent specifically for next block, the next block is displayed in the top right of the screen
 
  //Drawing text for score, highscore, level, and next block
  win.drawString(xIndent, ySpacing, "Level:");
  win.drawString(valuexIndent, ySpacing, to_string(getLevel()));
 
  //special placement of next score
  win.drawString(nextBlockIndent, ySpacing, "Next:");

  //we are moving down a row so double the spacing
  ySpacing += ySpacing; 
  win.drawString(xIndent, ySpacing, "Score:");
  win.drawString(valuexIndent, ySpacing, to_string(score.getCurrScore()));

  //double the spacing
  ySpacing += ySpacing;
  win.drawString(xIndent, ySpacing, "Hi Score:");
  win.drawString(valuexIndent, ySpacing, to_string(score.getHighScore()));
}

//draws the hint
void GraphicsDisplay::showHint(const vector <vector <int>> &coords) {
  for(auto &n : coords) {
    int row = n[0];
    int col = n[1];
    fillCell(row, col, Xwindow::Black);
  }
}

void GraphicsDisplay::clear() {
  //wipes the entire display
  win.fillRectangle(0, 0, totalLength, totalHeight, clearColour);
} 

//returns the proper colour, or black otherwise
int GraphicsDisplay::symbolToColour(const char symbol) {
  auto iter = symToColour.find(symbol);
  if(iter == symToColour.end()) return Xwindow::White;
  else return iter->second;
}

//Each Cell has a white border outline and a filled coloured center
void GraphicsDisplay::fillCell(const int row, const int col, int colour) {
  int border = 3; //how thick the white border between cells are

  int startX = col * cellWidth + border; //the starting X pixel position for filling the cell
  int startY = row * cellHeight + border + topSpace; //the starting Y pixel position for filling the cell

  int fillWidth = cellWidth - (border * 2); //only fills the center of the cell with colour (leaves a border)
  int fillHeight = cellHeight - (border * 2); //only fills the center of the cell with colour (leaves a border)

  win.fillRectangle(startX, startY, fillWidth, fillHeight, colour); //draws the rectangle
}

//Draws the next block. Imagine a mini grid in the top right of the window in which we draw the next block
void GraphicsDisplay::drawNextBlock(const vector <vector <char>> & layout, int colour) {
  int nextBlockAreaLength = totalLength / 2; //The length of the top section of the mini grid
  int nextBlockStartX = totalLength / 2; //The starting X pixel position for drawing next block
  int nextBlockAreaHeight = topSpace; //Y dimension of the top section of the grid
  int nextBlockStartY = 0; //The starting Y pixel position for drawing next block

  int numCellsX = 4, numCellsY = 2; //Our mini grid of 4x2 cells. Note all block designs only use the first 2 rows so no point in drawing 2 empty rows. Normally would be 4x4
  int nextCellWidth = nextBlockAreaLength / numCellsX; //The width of each cell in next block
  int nextCellHeight = nextBlockAreaHeight / numCellsY; //The height of each cell in next block
  int border = 1; //the border between cells. Smaller because next block is drawn smaller

  //clears the previous drawing of next block
  win.fillRectangle(nextBlockStartX, nextBlockStartY, nextBlockAreaLength, nextBlockAreaHeight, clearColour);
  
  //draws the layout of the next blockz. Currenently in the top left of the screen
  for(int i = 0; i < numCellsX; i++) {
    for(int j = 0; j < numCellsY; j++) {
      if(layout[i][j] != ' ') { 
        int startX = nextBlockStartX + (j * nextCellWidth) + border;
        int fillWidth = nextCellWidth - (border * 2);

        int startY = nextBlockStartY + (i * nextCellHeight) + border;
        int fillHeight = nextCellHeight - (border * 2);

        win.fillRectangle(startX, startY, fillWidth, fillHeight, colour);
      }
    }
  }
}

