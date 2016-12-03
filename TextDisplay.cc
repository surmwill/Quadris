#include "TextDisplay.h"
#include "SubscriptionType.h"
#include "Score.h"
#include "View.h"
#include "Subject.h"
#include "BlockLib.h"

using namespace std;

//The gris s intially empty
TextDisplay::TextDisplay(int level, int rows, int cols) level{level} {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; i++) {
      textGrid[i].emplace_back(' ');
    }
  }
}

//notifications of a cells states
void TextDisplay::notify(const Subject &whoNotified) {
  bool specialCell = false;
  int row = whoNotified.getCoords()[0];
  int col = whoNotified.getCoords()[1];

  if(row == -1 && col == -1) specialCell = true;

  if(specialCell) nextBlock = blockLib.getBlockLayout(whoNotified.getSymbol());
  textGrid[row][col] = whoNotified.getSymbol();
}

//displays the board in text
void TextDisplay::display(const Score &score) {
  int spacing = 4;
  int dashLength = 15;

  //Top of board
  cout << "Level: ";
  cout << setw(spacing);
  cout << level; << endl;
  cout << "Score: ";
  cout << setw(spacing);
  cout << score.getCurrScore();
  cout << "Hi Score: ";
  cout << setw(spacing);
  cout << score.getHighScore();
  printDashes(dashLength);
 
  //grid
  for(auto &rows : textGrid) {
    for(auto &cols : rows) {
      cout << cols;
    }
    cout << "\n";
  }
  printDashes(dashLength);

  //next block
  cout << "Next:";
  for(auto &rows : nextBlock) {
    for(auto &cols : rows) {
      cout << cols;
    }
    cout << "\n";
  }
  
}

//colours the grid with a hint
void TextDisplay::showHint(const vector <vector <int>> &coords) {
  int row; 
  int col;

  for(auto &n : coords) {
    row = n[0];
    col = n[1];
    textGrid[row][col] = '?'
  }
}

//clears the grid, but not anything else
void TextDisplay::clear() {
  for(auto &row : textGrid) {
    for(auto &col : row) {
      col = ' ';
    }
  }
  nextBlock.clear();
}

void TextDisplay::printDashes(int numDashes) {
  for(int i = 0; i < numDashes; i++) {
    cout << '-';
  }
  cout << "\n";
}

void TextDisplay::setLevel(const int level) {
  this->level = level;
}
