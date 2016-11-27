#include "ViewController.h"
#include "View.h"
#include "Score.h"
#include <vector>

using namespace std;

ViewController::ViewController(): score{new Score{0}} { 
  views.emplace_back(new TestDisplay{});
  views.emplace_back(new GraphicsDisplay{});
}

void ViewController::updateView() {
}

void ViewController::updateView(vector <vector <int>>) {
}

void ViewController::setScoreMultiplier(int multiplier) {
  score.setScoreMultiplier(multiplier);
}
