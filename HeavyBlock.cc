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

void HeavyBlock::rotatecw() {
  Block::rotatecw();
  Block::down();
}

void HeavyBlock::rotatecc() {
  Block::rotatecc();
  Block::down();
}

bool HeavyBlock::down() {
  Block::down();
  Block::down();
}

