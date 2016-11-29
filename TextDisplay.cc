#include "TextDisplay.h"
#include "SubscriptionType.h"
#include "Score.h"
#include "View.h"
#include "Subject.h"

using namespace std;

TextDisplay::TextDisplay(int rows, int cols) {
  for(int i = 0; i < rows; i++) {
    for(int i = 0; i < cols; i++) {
      textGrid[i].emplace_back(' ');
    }
  }
}

void TextDisplay::notify(Subject &whoNotified) {
}

void TextDisplay::display(const Score &score) {
}

void TextDisplay::display(const Score &score, const vector <vector <int>> &coords) {
}

