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

virtual void Block::rotate(bool cc) {
  // make a rotated block
  vector<Cell> rotatedBlock;
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      // create new cell
      Cell newCell;

      // Find the index of the Cell who will replace the current cell
      int oldLocation = ((13+i) - (4*j)) - 1;
      if (cc){
        oldLocation = (15 - oldLocation);
      }

      // make sure that the rotate is valid
      if (!blockCells[oldLocation].filled() || memberCell(oldLocation)){
        // if the destination of the cell at oldLocation is blocked, cancel rotation
        if (blockCells[((i*4) + j)].filled() && !memberCell((i*4)+j)){
          return;
        }

        // set new cell content
        Cell.setContent(blockCells[oldLocation]);
      }
    }
  }

  // set the block cells to their rotated configuration
  for (int i = 0; i < 15; i++){
    blockCells[i]->setContent(&rotatedBlock[i]);
  }
}

bool memberCell(int index){
  for (int i: filledIndices){
    if (index == i){
      return true;
    }
  }
  return false;
}

virtual void Block::down() {
}

virtual bool Block::autoDrop() {
}

vector <Cell*>* Block::getBlockCells() {
  return blockCells;
}
