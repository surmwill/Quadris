#include <vector>
#include "BlockController.h"
#include "Level.h"
#include "Grid.h"
#include "Block.h"
#include "Info.h"
#include "Subscriptions.h"
#include <iostream>

using namespace std;

BlockController::BlockController(Level *const level, Grid *grid): grid{grid},
  level{level}, currBlock{nullptr}, nextBlock{level->genBlock()} {
  genBlock(); //intializes currBlock based on nextBlocks value

  for(int i = 0; i < blockHeight; i++) {
    for(int j = 0; j < blockWidth; j++) {
      generatingArea.emplace_back(grid->getCell(i, j));
    }
  }
}

void BlockController::left(int multi) {
  currBlock->left(multi);
}

void BlockController::right(int multi) {
  currBlock->right(multi);
}

void BlockController::down(int multi) {
  currBlock->down(multi);
}

void BlockController::rotatecc(int multi) {
  currBlock->rotate(true, multi);
}

void BlockController::rotatecw(int multi) {
  currBlock->rotate(false, multi);
}

void BlockController::drop() {
  currBlock->drop();
  genBlock();
}

void BlockController::nextBlockNotification() {
  int blockWidth = 4;
  int blockHeight = 4;
  Cell * specialCell = grid->getCell(-1, -1); //the special cell has unqiue dimensions -1, -1

  for(int i = 0; i < blockWidth; i++) {
    for(int j = 0; j < blockHeight; j++) {
       char symbol = nextBlock->getCell(i, j)->getInfo().symbol;
       if(symbol != ' ') {
         specialCell->setSymbol(symbol);
         return;
       }
    }
  }
}

void BlockController::genBlock() {
  // free and replace the old currBlock
  delete currBlock;
  currBlock = nextBlock;
  nextBlock = level->genBlock();
  nextBlockNotification();

  attachCurrBlockToGrid();
}

void BlockController::attachCurrBlockToGrid() {
  for (int i = 0; i < currBlock->getBlockLen(); i++){
    for (int j = 0; j < currBlock->getBlockLen(); j++){
      // get a Cell from the grid
      Cell * gridCell = grid->getCell(i, j);

      // fill the grid cell and replace the block cell
      gridCell->setContent(currBlock->getCell(i, j));
      currBlock->setCell(i, j, gridCell);
    }
  }
}

void BlockController::setBlock(char type){
  delete currBlock;
  currBlock = level->genBlock(type);
  attachCurrBlockToGrid();
}

void BlockController::restart() {
  grid->reset();
  genBlock();
}
