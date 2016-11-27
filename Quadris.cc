#include "LevelController.h"
#include "BlockController.h"
#include "ViewController.h"
#include "HintEngine.h"
#include "Quadris.h"
#include <string>

using naemspace std;

class Grid;

Quadris::Quadris(int level): level{level} lc{new LevelController{level}}, bc{new BlockController{Grid *grid}},
  vc{new ViewController{}}, hintEngine{new HintEngine{&bc}} {}

void Quadris::left() {
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
