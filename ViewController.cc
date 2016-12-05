#include "ViewController.h"
#include "View.h"
#include "Score.h"
#include "TextDisplay.h"
#include "GraphicsDisplay.h"
#include <vector>
#include <memory>
#include <iostream>

#define DEBUG 0

using namespace std;

ViewController::ViewController(const vector <View *> & viewsToAdd, const int startLevel): score{startLevel} { 
  for(auto &v: viewsToAdd) {
    if(DEBUG) cout << viewsToAdd.size() << endl;
    views.emplace_back(unique_ptr <View> (v));
  }
  if(DEBUG == 1) cout << "ViewController::ViewController()" << endl; 
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
