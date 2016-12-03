#include "HeavyBlock.h"
#include "Block.h"
#include <vector>

using namespace std;

HeavyBlock::HeavyBlock(vector <char> blockDesign, int levelGenerated, int blockSize):
  Block{blockDesign, levelGenerated, blockSize} {}

// The below functions do not account for the command multiplier

void HeavyBlock::left() {
  Block::left();
  down();
}

void HeavyBlock::right() {
  Block::right();
  down();
}

void HeavyBlock::rotatecw() {
  Block::rotatecw();
  down();
}

void HeavyBlock::rotatecc() {
  Block::rotatecc();
  down();
}

bool HeavyBlock::down() {
  Block::down();
  Block::down();
}

