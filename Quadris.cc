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
  //Sets the starting sequence if neccessary
  if(startingSequence.length() > 0) lc->setFilename(startingSequence);

  //sets the seed
  if(!newSeed) srand(124325);

  //constructs the score
  Score * score = new Score;

  //construct the views and view controller
  vector <View *> views;
  views.emplace_back(new TextDisplay{startLevel, 18, 11});
  if(!textOnly) views.emplace_back(new GraphicsDisplay{startLevel});

  vc = unique_ptr <ViewController> (new ViewController {views, score});
   
  //constructs the grid
  Grid * grid = new Grid{views, score};

  //constructs the block controller
  bc = unique_ptr <BlockController> (new BlockController {lc->getLevel(), grid});

  //constructs the hint engine
  hintEngine = unique_ptr <HintEngine> (new HintEngine{bc});
 
  vc->updateView();
}

void Quadris::left(int multi) {
  bc->left(multi);
  vc->updateView();
}

void Quadris::right(int multi) {
  bc->right(multi);
  vc->updateView();
}

void Quadris::down(int multi) {
  bc->down(multi);
  vc->updateView();
}

void Quadris::drop(int multi) {
  cout << "droppped" << endl;
  for(int i = 0; i < multi; i++) {
    bc->drop();
    vc->updateView();
  }
}

void Quadris::rotatecc(int multi) {
  bc->rotatecc(multi);
  vc->updateView();
}

void Quadris::rotatecw(int multi) {
  bc->rotatecw(multi);
  vc->updateView();
}

void Quadris::levelup(int multi) {
  for(int i = 0; i < multi; i++) { 
    level == 4 ? level = 0 : level++;
    lc->changeLevel(level);
    vc->setLevel(level);
  }
}

void Quadris::leveldown(int multi) {
  for(int i = 0; i < multi; i++) {
    level == 0 ? level = 4 : level--;
    lc->changeLevel(level);
    vc->setLevel(level);
  }
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
  bc->restart();
  vc->updateView();
}
