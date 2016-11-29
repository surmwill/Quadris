#include "LevelController.h"
#include "BlockController.h"
#include "ViewController.h"
#include "HintEngine.h"
#include "Quadris.h"
#include "Grid.h"
#include <string>

using naemspace std;

class Grid;

Quadris::Quadris(int level): level{level} lc{new LevelController{level}}, vc{new ViewController{}} {
  Grid = new Grid{}; //attach view observers here to each grid cell
  bc = new BlockController(&grid);
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
 vc.updateView(hintEngine.hint());
}

void Quadris::restart() {
  vc.restart();
}
