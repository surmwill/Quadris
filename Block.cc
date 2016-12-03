#include "Block.h"
#include <vector>
#include "Cell.h"

using namespace std;

Block::Block(vector <char> blockDesign, int levelGenerated, int blockSize) {
  blockNumber++;
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
  // maybe rename the variable autoDrop so that it does not share a name with the function
  return autoDrop;
}

virtual void Block::rotate(bool cc) {
  // keep track of the new locations of filled cells
  vector<int> newMembers;

  // make a rotated block
  vector<Cell> rotatedBlock;

  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      // create new cell
      Cell newCell {' ', 0, -1}; // level set to -1, not a filled part of the block

      // Find the index of the Cell who will replace the current cell
      int oldLocation = ((13+i) - (4*j)) - 1;
      if (cc){
        oldLocation = (15 - oldLocation);
      }

      // make sure that the rotation is valid
      if (memberCell(oldLocation)){
        // if the destination of the cell at oldLocation is blocked, cancel rotation
        if (blockCells[((i*4) + j)].filled() && !memberCell((i*4)+j)){
          return;
        }

        // add the current location as a filled cell
        newMembers.push_back((i*4) + j);

        // set new cell content, fill current cell
        Cell.setContent(blockCells[oldLocation]);
      }

      // add the new cell to the rotated block
      rotatedBlock.push_back(newCell);
    }
  }

  // set the block cells to their rotated configuration
  for (int i = 0; i < 15; i++){
    blockCells[i]->setContent(&rotatedBlock[i]);
  }
}

bool Block::memberCell(int index){
  for (int i: filledIndices){
    if (index == i){
      return true;
    }
  }
  return false;
}

virtual void Block::down() {
  // if the cell can move down
  if (droppable(12) && droppable(13) && droppable(14) && droppable(15)){
    // drop all cells starting from the bottom right of the block
    for (int i = 15; i > 0; i--){
      blockCells[i]->drop()
    }
  } else {
    autoDrop = true;
  }
}

virtual void Block::left() {
  // if the cell can move left
  if (moveableLeft(0) && moveableLeft(4) && moveableLeft(8) && moveableLeft(12)){
    // move all cells starting from the top left of the block
    for (int i = 0; i < 15; i++){
      blockCells[i]->moveLeft()
    }
  }
}

virtual void Block::right() {
  // if the cell can move right
  if (moveableRight(3) && moveableRight(7) && moveableRight(11) && moveableRight(15)){
    // move all cells starting from the bottom right of the block
    for (int i = 15; i > 0; i--){
      blockCells[i]->moveRight()
    }
  }
}

void Block::droppable(int index, int cellsToCheck){
  // if there is no bottom filled cell in this column
  if (cellsToCheck <= 0) {
    return true;
  }

  // if this is the bottom filled cell in this column
  if (blockCells[index]->filled()){
    return blockCells[index]->droppable();
  } else {
    // find the bottom filled cell in the column
    return droppable(index-4, cellsToCheck-1);
  }
}

void Block::moveableLeft(int index, int cellsToCheck){
  // if there is no leftmost filled cell in this row
  if (cellsToCheck <= 0) {
    return true;
  }

  // if this is the bottom filled cell in this column
  if (blockCells[index]->filled()){
    return blockCells[index]->moveableLeft();
  } else {
    // find the bottom filled cell in the column
    return droppable(index+1, cellsToCheck-1);
  }
}

void Block::moveableRight(int index, cellsToCheck){
  // if there is no bottom filled cell in this column
  if (cellsToCheck <= 0) {
    return true;
  }

  // if this is the bottom filled cell in this column
  if (blockCells[index]->filled()){
    return blockCells[index]->moveableRight();
  } else {
    // find the bottom filled cell in the column
    return droppable(index-1, cellsToCheck-1);
  }
}

virtual void Block::drop(){
  // move down until you can no longer
  while (autoDrop()){
    down();
  }
}

vector <Cell*>* Block::getBlockCells() {
  return blockCells;
}
