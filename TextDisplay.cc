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
}

void TextDisplay::notify(const Subject &whoNotified) {
  bool specialCell = false;
  int row = whoNotified.getInfo().row;
  int col = whoNotified.getInfo().col;
  char symbol = whoNotified.getInfo().symbol;

  //checl if we are being notified of what the next cell is
  if(row == -1 && col == -1) specialCell = true;
  if(specialCell) {
    nextBlock.clear();
    for(auto &n : getBlockLib().getBlockLayout(symbol)) {
      nextBlock.emplace_back(n);
    }
    return;
  }
    
  textGrid[row][col] = symbol;
}

void TextDisplay::display(const Score &score) {
  int spacing = 4; //number of digits reserved for displaying the score number, high score number, and level number
  int dashLength = 11; //number of dashes to seperate the screen

  //Top of board
  cout << "\n";
  cout << "Level:    ";
  cout << setw(spacing);
  cout << getLevel() << endl;
  cout << "Score:    ";
  cout << setw(spacing);
  cout << score.getCurrScore() << endl;
  cout << "Hi Score: ";
  cout << setw(spacing);
  cout << score.getHighScore() << endl;
  printDashes(dashLength);
 
  //grid
  for(auto &rows : textGrid) {
    for(auto &cols : rows) {
      cout << cols;
    }
    cout << "\n";
  }
  printDashes(dashLength);

 // next block
  cout << "Next:" << endl;
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
