#include "LevelController.h"
#include "BlockController.h"
#include "ViewController.h"
#include "HintEngine.h"
#include "Quadris.h"
#include "Grid.h"
#include "View"
#include "GraphicsDisplay"
#include "TextDisplay"
#include <string>
#include <vector>

using namespace std;

class Grid;

Quadris::Quadris(bool textOnly, int seed, std::string startingSequence = "", int startLevel = 0): level{startingLevel}, 
  lc{new LevelController{startingLevel}} {
  
  //construct the views and view controller
  vector <View *> views;
  views.emplace_back(new TextDisplay{startLevel});
  if(!textOnly) views.emplace_back(new GraphicsDisplay{startLevel});
  ViewController vc{views, startLevel};
   
  //constructs the grid
  Grid = new Grid{views}; 

  //constructs the block controller
  bc = new BlockController(&grid);

  //constructs the hint engine
  hintEngine = new HintEngine(&bc);
}

void Quadris::left() {
  bc.left();
  vc.updateView();
}

void Quadris::right() {
  bc.right();
  vc.updateView();
}

void Quadris::down() {
  bc.down();
  vc.updateView();
}

void Quadris::rotatecc() {
  bc.rotatecc();
  vc.updateView();
}

void Quadris::rotatecw() {
  bc.rotatecw();
  vc.updateView();
}

void Quadris::levelup() {
  level == 4 ? level = 0 : level++;
  levelController.changeLevel(level);
}

void Quadris::leveldown() {
  level == 0 ? level = 4 : level--;
  levelController.changeLevel(level);
}

void Quadris::setSequence(string filename) {
  levelController.setFileName(filename);
}

void Quadris::setBlock(char type) {
  bd.setBlock(type);
}

void Quadris::hint() {
 vc.showHint(hintEngine.hint());
}

void Quadris::restart() {
  vc.restart();
}
