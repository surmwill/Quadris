#include "ViewController.h"
#include "View.h"
#include "Score.h"
#include <vector>

using namespace std;

ViewController::ViewController(): score{new Score{0}} { 
  views.emplace_back(new TestDisplay{});
  views.emplace_back(new GraphicsDisplay{});
}

int Quadris::ViewController::getCurrentScore() {
}

int Quadris::ViewController::getHighScore() {
}
