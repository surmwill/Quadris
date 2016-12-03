#ifndef HEAVY_BLOCK_H
#define HEAVY_BLOCK_H 1

#include "Block.h"
#include <vector>

class HeavyBlock: public Block {
 public:
  HeavyBlock(std::vector <char> blockDesign, int levelGenerated, int blockSize = 16);
  void left() override;
  void right() override;
  void rotatecw() override;
  void rotatecc() override;
  bool down() override;
};

#endif 
