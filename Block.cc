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

virtual void Block::left() {
}

virtual void Block::right() {
}

virtual bool autoDrop(){
  return autoDrop();
}

virtual void Block::rotate(bool cc) {
  // keep track of the new locations of filled cells
  vector<int> newMembers;

  // make a rotated block
  vector<Cell> rotatedBlock;

  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
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
  // if the cell can be dropped
  if (droppable(12) && droppable(13) && droppable(14) && droppable(15)){
    // drop all cells starting from the bottom right of the block
    for (int i = 15; i > 0; i--){
      blockCells[i]->drop()
    }
  } else {
    autoDrop = true;
  }
}

void Block::droppable(int index){
  // if there is no bottom filled cell in this column
  if (index <= 0) {
    return true;
  }

  // if this is the bottom filled cell in this column
  if (blockCells[index]->filled()){
    return blockCells[index]->droppable();
  } else {
    // find the bottom filled cell in the column
    return droppable(index-4);
  }
}

virtual void Block::drop(){
  while (autoDrop){
    down();
  }
}

vector <Cell*>* Block::getBlockCells() {
  return blockCells;
}
