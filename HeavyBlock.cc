#include "HeavyBlock.h"
#include "Block.h"
#include <vector>

using namespace std;

HeavyBlock::HeavyBlock(vector <char> blockDesign, int levelGenerated, int blockSize):
  Block{blockDesign, levelGenerated, blockSize} {}

// The below functions do not account for the command multiplier

void HeavyBlock::left() {
  Block::left();
  Block::down();
}

void HeavyBlock::right() {
  Block::right();
  Block::down();
}

void HeavyBlock::rotate(bool cc) {
  Block::rotate(cc);
  Block::down();
}

void HeavyBlock::down() {
  Block::down();
  Block::down();
}

