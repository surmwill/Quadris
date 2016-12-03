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

virtual void Block::rotatecw() {
  vector<Cell*> newBlock;
  int cellNum = 0;

  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (n <= 15){
        blockCells = newBlock;
        return;
      }
      newBlocks.push_back(blockCells[((13 + i) - (4 * j))]);
    }
  }
}

virtual void Block::rotatecc() {
  vector<Cell*> newBlock;
  int cellNum = 0;

  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (n <= 15){
        blockCells = newBlock;
        return;
      }
      newBlocks.push_back(blockCells[((4 * j) + (4 - i))]);
    }
  }
}

virtual void Block::down() {
}

virtual bool Block::autoDrop() {
}

vector <Cell*>* Block::getBlockCells() {
  return blockCells;
}
