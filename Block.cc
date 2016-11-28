#include "Block.h"
#include <vector>
#include "Cell.h"

using namespace std;

Block::Block(vector <char> blockDesign, int levelGenerated, int blockSize) {
  for(auto n:blockCells && bd:blockDesign) {
    for(auto m:blockCells) {
      if(!*n == *m) (*n)->attach(*m);
    }
    (*n)->setContent(*bd, levelGenerated, blockSize);
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
