#include "Block.h"
#include <vector>
#include "Cell.h"

using namespace std;

Block::Block(vector <char> blockDesign, int levelGenerated, int blockSize) {
  blockNumber++;
  blockLen = blockSize;
  for(auto bd:blockDesign) {
    blockCells.emplace_back(new Cell{*bd, levelGenerated, blockNumber, blockSize);
  }

  for(auto n:blockCells) {
    for(auto m:blockCells) {
      if(!*n == *m) (*n)->attach(*m);
    }
  }
}

virtual bool autoDrop(){
  return shouldDrop;
}

virtual void Block::rotate(bool cc) {
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
      if (cc){ oldLocation = (((blockLen^2) - 1) - oldLocation); }

      // make sure that the rotation is valid
      if (memberCell(oldLocation)){
        // if the destination of the cell at oldLocation is blocked, cancel rotation
        if (blockCells[currentIndex].filled() && !memberCell(currentIndex)){
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

virtual void Block::down(){
  if (canBeMoved(Direction::Down)){
    for (int i = ((blockLen^2) - 1); i >; i--){
      blockCells[i]->drop()
    }
  } else {
    // mark the block as having been placed
    autoDrop = true;
  }
}

virtual void Block::left() {
  // if the cell can move left
  if (canBeMoved(Direction::Left)){
    // move all cells starting from the top left of the block
    for (int i = 0; i < 15; i++){
      blockCells[i]->moveLeft()
    }
  }
}

virtual void Block::right() {
  // if the cell can move right
  if (canBeMoved(Direction::Right)){
    // move all cells starting from the bottom right of the block
    for (int i = 15; i > 0; i--){
      blockCells[i]->moveRight()
    }
  }
}

bool Block::canBeMoved(Block::Direction d) {
  // get proper loop bounds to capture the right cells
  int step;
  int start;
  int end;

  switch(d) {
    case (Direction::Down):
      // all bottom cells
      step = 1 ;
      start = (blockLen*(blockLen-1));
      end = blockLen^2;
    case (Direction::Left):
      // all leftmost cells
      step = blockLen;
      start = 0;
      end = (blockLen*(blockLen-1));
    case (Direction::Right):
      // all rightmost cells
      step = blockLen;
      start = blockLen-1;
      end = blockLen^2;
  }

  //check to see if the cells can move
  bool canBeMoved = true;
  for (int col = start; col < end; col += step){
    canBeDropped = (canBeDropped && movable(col, blockLen, d));
  }

  return canBeMoved;
}

bool Block::movable(int index, int cellsToCheck, Block::Direction d){
  // set direction-specific parameters
  int step;
  bool (*movement);
  switch(d){
    case(Direction::Down):
      step = -4;
      movement = &blockCells[index]->droppable;
    case(Direction::Left):
      step = 1;
      movement = &blockCells[index]->movableLeft();
    case(Direction::Right):
      step = -1;
      movement = &blockCells[index]->movableRight();
  }

  // if there is no filled cell in this row or column
  if (cellsToCheck <= 0){
    return true;
  }

  // check movability
  if (blockCells[index]->filled){
    return movement();
  } else {
    return moveable()index += step, cellsToCheck - 1;
  }

}

virtual void Block::drop(){
  // move down until you can no longer
  while (autoDrop()){
    down();
  }
}

Cell * getCell(int row, int col){
  return blockCells[(blockLen*row) + col];
}


vector <Cell*>* Block::getBlockCells() {
  return blockCells;
}
