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

#define DEBUG 1

using namespace std;

class Grid;

Quadris::Quadris(int seed, bool newSeed, bool textOnly, std::string startingSequence, int startLevel): level{startLevel}, 
  lc{new LevelController{startLevel}} { 

  if(DEBUG) cout << "new seed?" << newSeed << endl;

  if(DEBUG) cout << startingSequence << endl;
  if(startingSequence.length() > 0) lc->setFilename(startingSequence);

  //sets the seed
  if(!newSeed) srand(124325);

  if(DEBUG == 1) cout << "constructing the Views" << endl;
  if(DEBUG) cout << "Text only? " << textOnly << endl;

  //construct the views and view controller
  vector <View *> views;
  views.emplace_back(new TextDisplay{startLevel, 18, 11});
  if(!textOnly) views.emplace_back(new GraphicsDisplay{startLevel});

  if(DEBUG == 1) cout << "constructing the view controller" << endl;
  vc = unique_ptr <ViewController> (new ViewController {views, startLevel});
   
  if(DEBUG == 1) cout << "constructing the Grid" << endl;
  //constructs the grid
  Grid * grid = new Grid{views}; 

  if(DEBUG == 1) cout << "constructing the BlockController" << endl;
  //constructs the block controller
  bc = unique_ptr <BlockController> (new BlockController {lc->getLevel(), grid});

  if(DEBUG == 1) cout << "constructing the HintEngine" << endl;
  //constructs the hint engine
  hintEngine = unique_ptr <HintEngine> (new HintEngine{bc});

  //Sets the starting sequence if neccessary
  if(startingSequence.length() > 0) lc->setFilename(startingSequence);
 
  if(DEBUG == 1) cout << "Quadris::Quadris()" << endl;
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
