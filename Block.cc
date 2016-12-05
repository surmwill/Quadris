#include "Block.h"
#include <vector>
#include "Cell.h"
#include <iostream>

#define DEBUG 1

using namespace std;

Block::Block(vector <char> blockDesign, int levelGenerated, int blockSize) {
  if(DEBUG == 1) cout << "Block construction started" << endl;
  blockLen = blockSize;
  for(auto bd:blockDesign) {
    // set the coordinates to (-1, -1) since the content will be taken and the cells discarded
    blockCells.emplace_back(new Cell{bd, blockSize, levelGenerated, -1, -1});
  }

  for(auto n:blockCells) {
    for(auto m:blockCells) {

      // Should Probably get rid of this ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      // if the coordinates of n and m are the same
      if ((((n->getInfo()).row) != ((m->getInfo()).row)) || (((n->getInfo()).col) != ((m->getInfo()).col))){
        n->attach(m);
      }
    }
  }
  if(DEBUG == 1) cout << "Block::Block()" << endl;
}

Block::~Block(){}

bool Block::autoDrop(){
  return shouldDrop;
}

void Block::rotate(bool cc) {
  if (DEBUG == 1) cout << "Block::rotate()" << endl;

  // keep track of the new locations of filled cells
  vector<int> newMembers;

  // make a rotated block
  vector<Cell> rotatedBlock;

  for (int i = 0; i < blockLen; i++){
    for (int j = 0; j < blockLen; j++){
      // create new cell
      Cell newCell {' ', 0, -1}; // level set to -1, not a filled part of the block

      // Keep track of indices
      int currentIndex = (blockLen*i) + j;
      int oldLocation = (((blockLen*(blockLen - 1))+i) - (blockLen*j));
      if (cc){ oldLocation = (((blockLen*blockLen) - 1) - oldLocation); }

      // make sure that the rotation is valid
      if (memberCell(oldLocation)){
        // if the destination of the cell at oldLocation is blocked, cancel rotation
        if (blockCells[currentIndex]->filled() && !memberCell(currentIndex)){
          return;
        }

        // add the current location as a filled cell
        newMembers.push_back(currentIndex);

        // set new cell content, fill current cell
        newCell.setContent(blockCells[oldLocation]);
      }

      // add the new cell to the rotated block
      rotatedBlock.push_back(newCell);
    }
  }

  // set the block cells to their rotated configuration
  filledIndices = newMembers;
  for (int i = 0; i < blockLen; i++){
    blockCells[i]->setContent(&rotatedBlock[i]);
  }
}

bool Block::memberCell(int index){
  // check list of member indices
  for (int i: filledIndices){
    if (index == i){
      return true;
    }
  }
  return false;
}

void Block::down(){
  if (DEBUG == 1) cout << "Block::down()" << endl;
  if (canBeMoved(Direction::Down)){
    if (DEBUG == 1) cout << "MOVE_DOWN" << endl;

    // move content starting from the bottom right of the block
    bool onBottom = false;

    for (int i = ((blockLen*blockLen) - 1); i >= 0; i--){
      // make sure we don't move the block off of the board
      Cell * newLocation = (blockCells[i]->drop());
      onBottom = (onBottom || (newLocation == nullptr));
      if (!onBottom){
        // point to new cell info location
        blockCells[i] = newLocation;
      }
    }
  } else {
    if (DEBUG == 1) cout << "DON'T_MOVE_DOWN" << endl;

    // mark the block as having been placed
    shouldDrop = true;
  }
}

void Block::left() {
  if (DEBUG == 1) cout << "Block::left()" << endl;

  // if the cell can move left
  if (canBeMoved(Direction::Left)){
    if (DEBUG == 1) cout << "MOVE_LEFT" << endl;

    // move content starting from the top left of the block
    bool onLeftEdge = false;

    for (int i = 0; i <= 15; i++){
      // make sure we don't move the block off of the board
      Cell * newLocation = (blockCells[i]->moveLeft());
      onLeftEdge = (onLeftEdge || (newLocation == nullptr));
      if (!onLeftEdge){
        // point to new cell info location
        blockCells[i] = newLocation;
      }
    }
  } else if (DEBUG == 1) cout << "DON'T_MOVE_LEFT" << endl;
}

void Block::right() {
  if (DEBUG == 1) cout << "Block::right()" << endl;

  // if the cell can move right
  if (canBeMoved(Direction::Right)){
    if (DEBUG == 1) cout << "MOVE_RIGHT" << endl;

    // move content starting from the bottom right of the block
    bool onRightEdge = false;

    for (int i = 15; i >= 0; i--){
      // make sure we don't move the block off of the board
      Cell * newLocation = (blockCells[i]->moveRight());
      onRightEdge = (onRightEdge || (newLocation == nullptr));
      if (!onRightEdge){
        // point to new cell info location
        blockCells[i] = newLocation;
      }
    }
  } else if (DEBUG == 1) cout << "DON'T_MOVE_RIGHT" << endl;
}

bool Block::canBeMoved(Block::Direction d) {
  if (DEBUG == 1) cout << "Block::canBeMoved()" << endl;

  // get proper loop bounds to capture the right cells
  int step = 0;
  int start = 0;
  int end = 0;

  switch(d) {
    case (Direction::Down):
      // all bottom cells
      step = 1;
      start = (blockLen*(blockLen-1));
      end = (blockLen*blockLen);
      break;
    case (Direction::Left):
     // all leftmost cells
      step = blockLen;
      start = 0;
      end = ((blockLen*(blockLen-1)) + 1);
      break;
    case (Direction::Right):
     // all rightmost cells
      step = blockLen;
      start = blockLen-1;
      end = (blockLen*blockLen);
      break;
  }

  //check to see if the cells can move
  bool canBeMoved = true;
  for (int i = start; i < end; i += step){
    cout << "CHECK ROW/COL" << endl;
    canBeMoved = (canBeMoved && movable(i, blockLen, d));
  }

  return canBeMoved;
}

bool Block::movable(int index, int cellsToCheck, Block::Direction d){
  if (DEBUG == 1) cout << "Block::movable(index: " << index << ", cell Total: " << blockCells.size() << ")" << endl;

  // if there is no filled cell in this row or column
  if (cellsToCheck <= 0){
    return true;
  }

  // check movability
  if ((blockCells[index]->filled()) && (!(blockCells[index]->getInfo()).set)){
    if (DEBUG == 1) cout << "Filled: " << index << endl;

    if (d == Direction::Down){
      return blockCells[index]->droppable();
    } else if (d == Direction::Left){
      return blockCells[index]->movableLeft();
    } else if (d == Direction::Right){
      return blockCells[index]->movableRight();
    } else {
      //unknown direction
      return false;
    }
  } else {
    if (DEBUG == 1) cout << "    empty" << endl;

    // set the step of Cells in the block
    int step = 0;
    if (d == Direction::Down){
      step = -4;
    } else if (d == Direction::Left){
      step = 1;
    } else if (d == Direction::Right){
      step = -1;
    }

    return movable(index += step, cellsToCheck - 1, d);
  }
}

int Block::getBlockLen(){
  return blockLen;
}

void Block::drop(){
  if (DEBUG == 1) cout << "Block::drop()" << endl;

  // move down until you can no longer
  while (!autoDrop()){
    down();
  }

  // set all block cells in place
  for (Cell * c: blockCells){
    c->setInPlace();
  }
}

Cell * Block::getCell(int row, int col){
  return blockCells[(blockLen*row) + col];
}

void Block::setCell(int row, int col, Cell * newCell){
  delete blockCells[(blockLen*row) + col];
  blockCells[(blockLen*row) + col] = newCell;
}

vector <Cell*>* Block::getBlockCells() {
  return &blockCells;
}
