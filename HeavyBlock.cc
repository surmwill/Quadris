#include "HeavyBlock.h"
#include "Block.h"
#include <vector>

using namespace std;

HeavyBlock::HeavyBlock(vector <char> blockDesign, int levelGenerated, int blockSize):
  Block{blockDesign, levelGenerated, blockSize} {}

// The below functions do not account for the command multiplier

void HeavyBlock::left() {
  Block::right();
  Block::down(1);
}

void HeavyBlock::right() {
  Block::right();
  Block::down(1);
}

void HeavyBlock::rotate(bool cc) {
  Block::rotate(cc);
  Block::down(1);
}

void HeavyBlock::down() {
  Block::down(1);
  Block::down(1);
}

