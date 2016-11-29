#include "Block.h"
#include <vector>
#include "Cell.h"

using namespace std;

Block::blockNumber = 0;

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
}

virtual void Block::rotatecc() {
}

virtual void Block::down() {
}

virtual bool Block::autoDrop() {
}

vector <Cell*>* Block::getBlockCells() {
  return blockCells;
}
