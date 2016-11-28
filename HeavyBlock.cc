#include "HeavyBlock.h"
#include "Block.h"
#include <vector>

using namespace std;

HeavyBlock::HeavyBlock(vector <char> blockDesign, int levelGenerated, int blockSize):
  Block{blockDesign, levelGenerated, blockSize} {}

void HeavyBlock::left() {
}

void HeavyBlock::right() {
}

void HeavyBlock::rotatecw() {
}

void HeavyBlock::rotatecc() {
}

bool HeavyBlock::autoDrop() {
}

bool HeavyBlock::drop() {
}

bool HeavyBlock::down() {
}

