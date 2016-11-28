#include "SubscriptionType.h"
#include "GraphicsDisplay.h"
#include "Score.h"
#include "View.h"
#include <vector>
#include "Subject.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(int rows, int cols) {}

void GraphicsDisplay::notify(Subject &whoNotified) {
}

void GraphicsDisplay::display(Score &score) {
}

void GraphicsDisplay::display(Score &score, vector <vector <int>> coords) {
} 
