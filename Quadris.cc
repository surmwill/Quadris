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
  vc.updateView();
}

void Quadris::right() {
}

void Quadris::down() {
}

void Quadris::rotatecc() {
}

void Quadris::rotatecw() {
}

void Quadris::levelup() {
}

void Quadris::leveldown() {
}

void Quadris::setSequence(string filename) {
}

void Quadris::dropBlockWithType(char type) {
}

void Quadris::hint() {
}

void Quadris::restart() {
}
