#include <vector>
#include "Level.h"
#include "Grid.h"
#include "Block.h"

using namespace std;

BlockController::BlockController(Level *level, Grid *grid): level{level}, grid{grid}, 
  currBlock{level->GenBlock()}, nextBlock{level->Genblock} {
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      genertingArea.emplace_back(grid.getCell(i, j));
    }
  }
}

void BlockController::left() {
  currBlock.left();
}

void BlockController::right() {
  currBlock.right();
}

void BlockController::down() {
  currBlock.down();
}

void BlockController::rotatecc() {
  currBlock.rotate(true);
}

void BlockController::rotatecw() {
  currBlock.rotate(false);
}

void BlockController::drop() {
  currBlock.drop();
}

void BlockController::genBlock() {
  currBlock = nextBlock;
  nextBlock = level.genBlock();
  attachCurrBlockToGrid();
}

void BlockController::attachCurrBlockToGrid() {
  for (int i = 0; i < currBlock.blockLen; i++){
    for (int j = 0; j < currBlock.blockLen; j++){
      // get a Cell from the grid
      Cell * gridCell = grid.getCell(i, j);

      // check to make sure that the game is not over
      if (gridCell.filled()){
        // replace this with something better
        // BlockController whould not output to the user
        cout << "GAME OVER" << endl;
        exit 0;
      }

      // fill the grid cell and replace the block cell
      gridCell.setContent(currBlock.getCell(i, j));
      currBlock.getCell(i, j) = gridCell;
    }
  }
}

void BlockController::setBlock(char type) {
  // what is this for?
}
