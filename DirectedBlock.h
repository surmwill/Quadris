#ifndef DIRECTED_BLOCK_H
#define DIRECTED_BLOCK_H 1

#include "Block.h"
#include <vector>

class DIRECTEDBlock: public Block {
 public:
  DirectedBlock(std::vector <char> blockDesign, int levelGenerated, int blockSize = 16);
  void left() override;
  void right() override;
  void rotatecw() override;
  void rotatecc() override;
  bool autoDrop() override; 
  bool drop() override;
  bool down() override;
};

#endif 
