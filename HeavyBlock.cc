#include "HeavyBlock.h"
#include "Block.h"
#include <vector>
#include "Grid.h"

using namespace std;

HeavyBlock::HeavyBlock(vector <char> blockDesign, int levelGenerated, int blockSize):
  Block{blockDesign, levelGenerated, blockSize} {}

// The below functions do not account for the command multiplier

void HeavyBlock::left(int multi) {
  for(int i = 0; i < multi; i++) { Block::left(1); }
  Block::down(1);
}

void HeavyBlock::right(int multi) {
  for(int i = 0; i < multi; i++) { Block::right(1); }
  Block::down(1);
}

void HeavyBlock::rotate(bool cc, int multi, Grid * g) {
  for(int i = 0; i < multi; i++) { Block::rotate(cc, 1, g); }
  Block::down(1);
}

void HeavyBlock::down(int multi) {
  for(int i = 0; i < multi; i++) { Block::down(1); }
  Block::down(1);
}

