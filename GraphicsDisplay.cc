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

  //if the row and column are not intialized we have a spcial cell
  if(row == -1 && col == -1) displayNextBlock(whoNotified.getSymbol(), 

  fillCell(row, col, symbolToColour(whoNotified.getSymbol());
}

void GraphicsDisplay::display(const Score &score) {
  int ySpacing = 10; //Y spacing between the texts of level, score, highscore, and the top of the screen
  int xIndent = 5; //X indent from the left side of the screen for level, score, and highscore text
  int valuexIndent = 80; //Indent from each of the texts to their associated value (ex highscore:      10)
 
  //Drawing text for score, highscore, and level
  win.drawString(xIndent, ySpacing, "Level:");
  win.drawString(valuexIndent, ySpacing, to_string(score.getLevel());

  ySpacing += ySpacing; //we are moving down a lone so double the spacing
  win.drawString(xIndent, ySpacing, "Score:");
  win.drawString(valuexIndent, ySpacing, to_string(score.getCurrScore());

  ySpacing += ySpacing;
  win.drawString(xIndent, ySpacing, "Hi Score:");
  win.drawString(valuexIndent, ySpacing, to_string(Score.getHighScore());

  //to do: draw next block somewhere
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
  iter == symToColour.end()? return Xwindow::black : return iter->second;
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

