#ifndef HEAVY_BLOCK_H
#define HEAVY_BLOCK_H 1

#include "Block.h"
#include <vector>

class HeavyBlock: public Block {
 public:
  HeavyBlock(std::vector <char> blockDesign, int levelGenerated, int blockSize = 4);
  void left(int mult) override;
  void right(int mult) override;
  void rotate(bool cc, int mult) override;
  void down(int mult) override;
};

#endif 
