#include "LevelController.h"
#include "BlockController.h"
#include "ViewController.h"
#include "HintEngine.h"
#include "Quadris.h"
#include "Grid.h"
#include "View.h"
#include "GraphicsDisplay.h"
#include "TextDisplay.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

class Grid;

Quadris::Quadris(int seed, bool newSeed, bool textOnly, std::string startingSequence, int startLevel): level{startLevel}, 
  lc{new LevelController{startLevel}} { 

  if(startingSequence.length() > 0) lc->setFilename(startingSequence);

  //sets the seed
  if(!newSeed) srand(124325);

  //construct the views and view controller
  vector <View *> views;
  views.emplace_back(new TextDisplay{startLevel, 18, 11});
  if(!textOnly) views.emplace_back(new GraphicsDisplay{startLevel});

  vc = unique_ptr <ViewController> (new ViewController {views, startLevel});
   
  //constructs the grid
  Grid * grid = new Grid{views, new Score()};

  //constructs the block controller
  bc = unique_ptr <BlockController> (new BlockController {lc->getLevel(), grid});

  //constructs the hint engine
  hintEngine = unique_ptr <HintEngine> (new HintEngine{bc});

  //Sets the starting sequence if neccessary
  if(startingSequence.length() > 0) lc->setFilename(startingSequence);
 
  vc->updateView();
}

void Quadris::left() {
  bc->left();
  vc->updateView();
}

void Quadris::right() {
  bc->right();
  vc->updateView();
}

void Quadris::down() {
  bc->down();
  vc->updateView();
}

void Quadris::drop() {
  bc->drop();
  vc->updateView();
}

void Quadris::rotatecc() {
  bc->rotatecc();
  vc->updateView();
}

void Quadris::rotatecw() {
  bc->rotatecw();
  vc->updateView();
}

void Quadris::levelup() {
  level == 4 ? level = 0 : level++;
  lc->changeLevel(level);
  vc->setLevel(level);
}

void Quadris::leveldown() {
  level == 0 ? level = 4 : level--;
  lc->changeLevel(level);
  vc->setLevel(level);
}

void Quadris::setSequence(string filename) {
  lc->setFilename(filename);
}

void Quadris::setBlock(char type) {
  bc->setBlock(type);
  vc->updateView();
}

void Quadris::hint() {
 vc->showHint(hintEngine->hint());
}

void Quadris::restart() {
  vc->restart();
}
