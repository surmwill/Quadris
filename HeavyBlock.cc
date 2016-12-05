#include "HeavyBlock.h"
#include "Block.h"
#include <vector>

using namespace std;

HeavyBlock::HeavyBlock(vector <char> blockDesign, int levelGenerated, int blockSize):
  Block{blockDesign, levelGenerated, blockSize} {}

// The below functions do not account for the command multiplier

void HeavyBlock::left(int mult) {
  for(int i = 0; i < mult; i++ ) {Block::left(1);}
  Block::down(1);
}

void HeavyBlock::right(int mult) {
  for(int i = 0; i < mult; i++) {Block::right(1);}
  Block::down(1);
}

void HeavyBlock::rotate(bool cc, int mult) {
  for(int i = 0; i < mult; i++) {Block::rotate(cc, 1);}
  Block::down(1);
}

void HeavyBlock::down(int mult) {
  for(int i = 0; i < mult; i++) {Block::down(1);}
  Block::down(1);
}

