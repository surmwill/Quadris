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

GraphicsDisplay::GraphicsDisplay(int rows, int cols): rows{rows}, cols{cols}, totalLength{cols * cellWidth}, 
  totalHeight{(rows * cellHeight) + topSpace}, Xwindow{totalLength, totalHeight} {
  symToColour.emplace_back(' ', Xwindow::White);
  symToColour.emplace_back('I', Xwindow::Magenta); 
  symToColour.emplace_back('J', Xwindow::Red);
  symToColour.emplace_back('L', Xwindow::Green);
  symToColour.emplace_back('O', Xwindow::Cyan);
  symToColour.emplace_back('D', Xwindow::Brown);
  symToColour.emplace_back('Z', Xwindow::Orange);
  symToColour.emaplce_back('T', Xwindow::Blue);

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

void GraphicsDisplay::display(const Score &score) {
  int ySpacing = 10; //Y spacing between the texts of level, score, highscore, and the top of the screen
  int xIndent = 5; //X indent from the left side of the screen for level, score, and highscore text
  int valuexIndent = 80; //Indent from each of the texts to their associated value (ex highscore:      10)
  int nextBlockIndent = (totalLength / 2) - 50; //Indent specifically for next block, the next block is displayed in the top right of the screen
 
  //Drawing text for score, highscore, level, and next block
  win.drawString(xIndent, ySpacing, "Level:");
  win.drawString(valuexIndent, ySpacing, to_string(score.getLevel());
 
  //special placement of next score
  win.drawString(nextBlockIndent, ySpacing, "Next:");

  ySpacing += ySpacing; //we are moving down a lone so double the spacing
  win.drawString(xIndent, ySpacing, "Score:");
  win.drawString(valuexIndent, ySpacing, to_string(score.getCurrScore());

  ySpacing += ySpacing;
  win.drawString(xIndent, ySpacing, "Hi Score:");
  win.drawString(valuexIndent, ySpacing, to_string(Score.getHighScore());
}

void GraphicsDisplay::display(const Score &score, const vector <vector <int>> &coords) {
}

void GraphicsDisplay::clear() {
  //wipe the display
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      fillCell(i, j, Xwindow::White);
    }
  }
  
  //redraw everything
  display();
} 

//returns the proper colour, or black otherwise
Xwindow GraphicsDisplay::symbolToColour(char symbol) {
  auto iter = symToColour.find(symbol);
  iter == symToColour.end()? return Xwindow::White : return iter->second;
}

//Each Cell has a white border outline and a filled coloured center
void GraphicsDisplay::fillCell(int row, int col, Xwindow colour) {
  int indent = 3; //how thick the white border between cells are

  int coordX = col * cellWidth + indent; //indent to allow white outline
  int coordY = row * cellHeight + indent + topSpace; //indent to allow white outline

  int fillWidth = cellWidth - (indent * 2); //only fills the center of the cell with colour
  int fillHeight = cellHeight - (indent * 2); //only fills the center of the cell with colour

  win.fillRectangle(coordX, coordY, fillWidth, fillHeight, colour); //draws the rectangle
}

void GraphicsDisplay::drawNextBlock(const vector <char> & layout, Xwindow colour) {
  int rowRestriction = 2; //For each block layout the actual block shapes only takes up 2 rows, no need to print an extra 2 blank rows
  int nextBlockAreaX = totalLength / 2;
  int nextBlockAreaY = topSpace;
  int nextCellWidth = nextBlockAreaX;
}
