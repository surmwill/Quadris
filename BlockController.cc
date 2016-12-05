#include <vector>
#include "BlockController.h"
#include "Level.h"
#include "Grid.h"
#include "Block.h"
#include "Info.h"
#include "Subscriptions.h"
#include <iostream>

#define DEBUG 1

using namespace std;

BlockController::BlockController(Level *const level, Grid *grid): grid{grid},
  level{level}, nextBlock{level->genBlock()} {
  genBlock(); //intializes currBlock based on nextBlocks value

  for(int i = 0; i < blockHeight; i++) {
    for(int j = 0; j < blockWidth; j++) {
      generatingArea.emplace_back(grid->getCell(i, j));
    }
  }
  
  if(DEBUG == 1) cout << "BlockController::BlockController()" << endl;
}

void BlockController::left() {
  currBlock->left();
}

void BlockController::right() {
  currBlock->right();
}

void BlockController::down() {
  currBlock->down();
}

void BlockController::rotatecc() {
  currBlock->rotate(true);
}

void BlockController::rotatecw() {
  currBlock->rotate(false);
}

void BlockController::drop() {
  currBlock->drop();
}

void BlockController::nextBlockNotification() {
  int blockWidth = 4;
  int blockHeight = 4;
  Cell * specialCell = grid->getCell(-1, -1); //the special cell has unqiue dimensions -1, -1

  if(DEBUG == 1) cout << "got grid->nextCell" << endl;

  for(int i = 0; i < blockWidth; i++) {
    for(int j = 0; j < blockHeight; j++) {
       char symbol = nextBlock->getCell(i, j)->getInfo().symbol;
       if(DEBUG == 1) cout << "Cell's symbol" << endl;
       if(symbol != ' ') {
         specialCell->setSymbol(symbol);
         return;
       }
    }
  }
}

void BlockController::genBlock() {
  currBlock = nextBlock;

  if(nextBlock == nullptr) return; 
  nextBlock = level->genBlock();
  if(DEBUG == 1) cout << "notification" << endl;
  nextBlockNotification();
  if(DEBUG == 1) cout << "BlockController::genBlock()" << endl;

  attachCurrBlockToGrid();
}

void BlockController::attachCurrBlockToGrid() {
  if(DEBUG == 1 ) cout << "attachCurrBlockToGrid()" << endl;
  for (int i = 0; i < currBlock->blockLen; i++){
    for (int j = 0; j < currBlock->blockLen; j++){
      // get a Cell from the grid
      Cell * gridCell = grid->getCell(i, j);

      // check to make sure that the game is not over
      if (gridCell->filled()){
        // replace this with something better
        // BlockController whould not output to the user
        cout << "GAME OVER" << endl;
        exit(0);
      }

      // fill the grid cell and replace the block cell
      gridCell->setContent(currBlock->getCell(i, j));
      currBlock->setCell(i, j, gridCell);
    }
  }
}

void BlockController::setBlock(char type) {
  // what is this for?
}
