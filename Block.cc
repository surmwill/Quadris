#include "Block.h"
#include <vector>
#include "Cell.h"

using namespace std;

Block::Block(vector <char> blockDesign, int levelGenerated, int blockSize) {
  for(auto bd:blockDesign) {
    blockCells.emplace_back(new Cell{*bd, levelGenerated, blockSize);

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

virtual bool autoDrop() {
}

virtual bool down() {
}
