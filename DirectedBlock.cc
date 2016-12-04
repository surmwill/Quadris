#include "DirectedBlock.h"
#include "Block.h"
#include <vector>

using namespace std;

DirectedBlock::DirectedBlock(vector <char> blockDesign, int levelGenerated, int blockSize):
  Block{blockDesign, levelGenerated, blockSize} {}

bool DirectedBlock::autoDrop() {
  int moveNum = 5; // moves the block into the middle of the board

  for (int i = 0; i < moveNum; i++){
    Block::left();
  }

  Block::drop();
  return true;
}

