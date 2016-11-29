#include "TextDisplay.h"
#include "SubscriptionType.h"
#include "Score.h"
#include "View.h"
#include "Subject.h"

using namespace std;

TextDisplay::TextDisplay(int rows, int cols) {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; i++) {
      textGrid[i].emplace_back(' ');
    }
  }
}

//notifications of a cells states
void TextDisplay::notify(Subject &whoNotified) {
}

//displays the board in text
void TextDisplay::display(const Score &score) {
  int spacing = 4;
  int dashLength = 15;

  //Top of board
  cout << "Level: ";
  cout << setw(spacing);
  cout << score->getLevel(); << endl;
  cout << "Score: ";
  cout << setw(spacing);
  cout << score.getCurrScore();
  cout << "Hi Score: ";
  cout << setw(spacing);
  cout << score.getHighScore();
  for(int i = 0; i < dashLength; i++) {
    cout << " " << endl;
  }

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols j++) {
      cout << textGrod[i];
    }
    cout << "\n";
   }
  }
}

//displays the board with a hint
void TextDisplay::display(const Score &score, const vector <vector <int>> &coords) {
}

