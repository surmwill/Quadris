#include "ViewController.h"
#include "View.h"
#include "Score.h"
#include <vector>

using namespace std;

//Intrializes the score and creates a vector of displays to constantly update
ViewController::ViewController(): score{new Score{0, 0}} { 
  views.emplace_back(new TestDisplay{});
  views.emplace_back(new GraphicsDisplay{});
}

//updates the score and then the views, passing the score
void ViewController::updateView() {
  score.updateCurrScore();

  for(auto &n : views) {
    n->updateView(score);
  }
}

//updates the views with the added hint position coloured in
void ViewController::showHint(const vector <vector <int>> & coords) {
  for(auto &n : views) {
    n->showHint(score, coords);
  }
}

//sets the level for the score, the Views don't need to know the level if score does
void ViewController::setLevel(int level) {
  score.setLevel(level);
}

void ViewController::restart() {
  score.clear();

  for(auto &n : views) {
    n->clear();
  }
}
