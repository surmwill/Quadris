#ifndef DIRECTED_BLOCK_H
#define DIRECTED_BLOCK_H 1

#include "Block.h"
#include <vector>

class DirectedBlock: public Block {
 public:
  DirectedBlock(std::vector <char> blockDesign, int levelGenerated, int blockSize = 16);
  bool autoDrop() override; 
};

#endif 
