#include "ViewController.h"
#include "View.h"
#include "Score.h"
#include "TextDisplay.h"
#include "GraphicsDisplay.h"
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

ViewController::ViewController(const vector <View *> & viewsToAdd, const int startLevel): score{startLevel} { 
  for(auto &v: viewsToAdd) {
    views.emplace_back(unique_ptr <View> (v));
  }
}

void ViewController::updateView() {
  score.updateCurrScore();

  for(auto &n : views) {
    n->display(score);
  }
}

void ViewController::showHint(const vector <vector <int>> & coords) {
  for(auto &n : views) {
    n->showHint(coords);
  }
}

void ViewController::setLevel(const int level) {
  score.setLevel(level);
 
  for(auto &n : views) {
    n->setLevel(level);
  }
  updateView();
  
}

void ViewController::restart() {
  score.clear();

  for(auto &n : views) {
    n->clear();
  }
  updateView();
}
