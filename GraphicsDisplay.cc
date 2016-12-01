#include "SubscriptionType.h"
#include "GraphicsDisplay.h"
#include "Score.h"
#include "View.h"
#include <vector>
#include "Subject.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(int rows, int cols): rows{rows}, cols{cols}, cellWidth{40},
  cellHeight{40}, topSpace{60} {}

void GraphicsDisplay::notify(const Subject &whoNotified) {
}

void GraphicsDisplay::display(const Score &score) {
}

void GraphicsDisplay::display(const Score &score, const vector <vector <int>> &coords) {
}

void GraphicsDisplay::clear() {
} 
