#include "TextDisplay.h"
#include "Subscriptions.h"
#include "Score.h"
#include "View.h"
#include "Subject.h"
#include "BlockLib.h"
#include "Info.h"
#include <iostream>
#include <iomanip> //setw
#include <vector>

#define DEBUG 1

using namespace std;

TextDisplay::TextDisplay(const int startLevel, const int rows, const int cols): View{startLevel} {
  vector <char> charRow;
  //the grid is intially empty
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      charRow.emplace_back(' ');
    }
    textGrid.emplace_back(charRow);
    charRow.clear();
  }
  if(DEBUG == 1) cout << "TextDisplay::TextDisplay" << endl;
}

void TextDisplay::notify(const Subject &whoNotified) {
  bool specialCell = false;
  int row = whoNotified.getInfo().coords[0];
  int col = whoNotified.getInfo().coords[1];
  char symbol = whoNotified.getInfo().symbol;

  if(row == -1 && col == -1) specialCell = true;

  if(specialCell) nextBlock = getBlockLib().getBlockLayout(symbol);
  textGrid[row][col] = symbol;
}

void TextDisplay::display(const Score &score) {
  int spacing = 4; //number of digits reserved for displaying the score number, high score number, and level number
  int dashLength = 15; //number of dashes to seperate the screen

  //Top of board
  cout << "Level: ";
  cout << setw(spacing);
  cout << getLevel() << endl;
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

void TextDisplay::showHint(const vector <vector <int>> &coords) {
  int row; 
  int col;

  for(auto &n : coords) {
    row = n[0];
    col = n[1];
    textGrid[row][col] = '?';
  }
}

void TextDisplay::clear() {
  for(auto &row : textGrid) {
    for(auto &col : row) {
      col = ' ';
    }
  }
  nextBlock.clear(); //clears next block
}

void TextDisplay::printDashes(int numDashes) {
  for(int i = 0; i < numDashes; i++) {
    cout << '-';
  }
  cout << "\n";
}
