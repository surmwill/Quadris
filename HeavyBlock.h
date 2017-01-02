#ifndef HEAVY_BLOCK_H
#define HEAVY_BLOCK_H 1

#include "Block.h"
#include <vector>

class Cell;
class Grid;

class HeavyBlock: public Block {
 public:
  HeavyBlock(std::vector <char> blockDesign, int levelGenerated, int blockSize = 4);
  void left(int multi) override;
  void right(int multi) override;
  void rotate(bool cc, int multi, Grid * g) override;
  void down(int multi) override;
};

#endif 
