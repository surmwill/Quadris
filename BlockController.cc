#include <vector>
#include "Level.h"
#include "Grid.h"
#include "Block.h"

using namespace std;

BlockController::BlockController(Level *level, Grid *grid): level{level}, grid{grid} {
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      Block::blockCells.emplace_back(grid.getCell(i, j));
    }
  }
 
  //note have to define the static varibale blockCells before constructing the object
  currBlock = level->genBlock();
  nextBlock = level->genBlock();
  
}

void BlockController::left() {
}

void BlockController::right() {
}

void BlockController::down() {
}

void BlockController::rotatecc() {
}

void BlockController::rotatecw() {
}

void BlockController::drop() {
}

void BlockController::genBlock() {
}

void BlockController::attachCurrBlockToGrid() {
}
