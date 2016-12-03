#include "SubscriptionType.h"
#include "GraphicsDisplay.h"
#include "Score.h"
#include "View.h"
#include "Subject.h"
#include "Window.h"
#include "BlockGen.h"
#include <map>
#include <vector>

using namespace std;

GraphicsDisplay::GraphicsDisplay(int level, int rows, int cols, int level): level{level}, rows{rows}, cols{cols}, totalLength{cols * cellWidth}, 
  totalHeight{(rows * cellHeight) + topSpace}, Xwindow{totalLength, totalHeight} {
  symToColour.emplace_back(' ', Xwindow::White);
  symToColour.emplace_back('I', Xwindow::Magenta); 
  symToColour.emplace_back('J', Xwindow::Red);
  symToColour.emplace_back('L', Xwindow::Green);
  symToColour.emplace_back('O', Xwindow::Cyan);
  symToColour.emplace_back('D', Xwindow::Brown);
  symToColour.emplace_back('Z', Xwindow::Orange);
  symToColour.emplace_back('T', Xwindow::Blue);

  clear();
}

//Filled the cell which notified the display
void GraphicsDisplay::notify(const Subject &whoNotified) {
  int row = whoNotified.getCoords()[0];
  int col = whoNotified.getCoords()[1];
  bool specialCell = false;
  char cellSymbol = whoNotified.getSymbol();
  
  //If the row and column of the cell are not initialized (coords are -1, -1) the special cell is notifying us of our next block
  if(row == -1 && col == -1) specialCell = true;

  if(specialCell) drawNextBlock(blockLib.getBlockLayout(cellSymbol), symbolToColour(cellSymbol));
  else fillCell(row, col, symbolToColour(whoNotified.getSymbol());
}

//Draws the top section of the board. The grid is drawn through notifications
void GraphicsDisplay::display(const Score &score) {
  int ySpacing = 10; //Y spacing between the texts of level, score, highscore, and the top of the screen
  int xIndent = 5; //X indent from the left side of the screen for level, score, and highscore text
  int valuexIndent = 80; //Indent from each of the texts to their associated value (ex highscore:      10)
  int nextBlockIndent = (totalLength / 2) - 50; //Indent specifically for next block, the next block is displayed in the top right of the screen
 
  //Drawing text for score, highscore, level, and next block
  win.drawString(xIndent, ySpacing, "Level:");
  win.drawString(valuexIndent, ySpacing, to_string(level);
 
  //special placement of next score
  win.drawString(nextBlockIndent, ySpacing, "Next:");

  ySpacing += ySpacing; //we are moving down a lone so double the spacing
  win.drawString(xIndent, ySpacing, "Score:");
  win.drawString(valuexIndent, ySpacing, to_string(score.getCurrScore());

  ySpacing += ySpacing;
  win.drawString(xIndent, ySpacing, "Hi Score:");
  win.drawString(valuexIndent, ySpacing, to_string(Score.getHighScore());
}

//draws the hint
void GraphicsDisplay::showHint(const vector <vector <int>> &coords) {
  for(auto &n : coords) {
    row = coords[0];
    col = coords[1];
    fillCell(row, col, Xwindow::Black);
  }
}

//clears the entire screen
void GraphicsDisplay::clear() {
  //wipes the entire display
  win.drawString(0, 0, totalWidth, totalHeight, clearColour);
} 

//returns the proper colour, or black otherwise
Xwindow GraphicsDisplay::symbolToColour(char symbol) {
  auto iter = symToColour.find(symbol);
  iter == symToColour.end()? return Xwindow::White : return iter->second;
}

//Each Cell has a white border outline and a filled coloured center
void GraphicsDisplay::fillCell(int row, int col, Xwindow colour) {
  int border = 3; //how thick the white border between cells are

  int coordX = col * cellWidth + border; //indent to allow white outline
  int coordY = row * cellHeight + border + topSpace; //indent to allow white outline

  int fillWidth = cellWidth - (border * 2); //only fills the center of the cell with colour
  int fillHeight = cellHeight - (border * 2); //only fills the center of the cell with colour

  win.fillRectangle(coordX, coordY, fillWidth, fillHeight, colour); //draws the rectangle
}

//draws the next block
void GraphicsDisplay::drawNextBlock(const vector <vector <char>> & layout, Xwindow colour) {
  int nextBlockAreaX = totalLength / 2; //X dimension of the top section of the grid
  int nextBlockIndentX = totalLength / 2; //The x coordinate where we start to draw the next block
  int nextBlockAreaY = topSpace; //Y dimension of the top section of the grid
  int nextBlockIndentY = 0; //The y cooridnate where we start to draw the next block. 0 because we want to start drawing it at the top of the screen

  int numCellsX = 4, int numCellsY = 2; //A mini grid of 4x2 cells. Note all block designs only use the first 2 rows so no point in drawing 2 empty rows. Normally would be 4x4
  int nextCellWidth = nextBlockAreaX / numCellsX; //The width of each cell
  int nextCellHeight = nextBlockAreaY / numCellsY; //The height of each cell
  int border = 1; //the border between cells. Smaller because next block is drawn smaller

  //clears the previous drawing of next block
  win.fillRectangle(nextBlockIndentX, nextBlockIndentY, nextBlockAreaX, nextBlockAreaY, clearColour);
  
  //draws the layout of the next blockz. Currenently in the top left of the screen
  for(unsigned int i = 0; i < numCellsX; i++) {
    for(unsigned int j = 0; j < numCellsY; j++) {
      if(layout[i][j] != ' ') { 
        int coordX = nextBlockIndentX + (j * nextCellWidth) + border;
        int fillWidth = nextCellWidth - (border * 2);

        int coordY = nextBlockIndentY + (i * nextCellHeight) + border;
        int fillHeight = nextCellHeight - (border * 2);

        win.fillRectangle(coordX, coordY, fillWidth, fillHeight, colour);
      }
    }
  }
}

void GraphicsDisplay::setLevel(const int level) {
  this->level = level;
}
