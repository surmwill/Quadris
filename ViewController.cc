#include "ViewController.h"
#include "View.h"
#include "Score.h"
#include <vector>

using namespace std;

ViewController::ViewController(const bool textOnly) { 
  views.emplace_back(new TextDisplay{});
  if(!textOnly) views.emplace_back(new GraphicsDisplay{});
}

void ViewController::updateView() {
  score.updateCurrScore();

  for(auto &n : views) {
    n->updateView(score);
  }
}

void ViewController::showHint(const vector <vector <int>> & coords) {
  for(auto &n : views) {
    n->showHint(score, coords);
  }
}

void ViewController::setLevel(const int level) {
  score.setLevel(level);
 
  for(auto &n : views) {
    n->setLevel(level);
  }
}

void ViewController::restart() {
  score.clear();

  for(auto &n : views) {
    n->clear();
  }
}
