#ifndef LEVEL_ZERO_H
#define LEVEL_ZERO_H 1

#include <vector>
#include <string>
#include "Level.h"

class Block;

class LevelZero: public Level {  
  public:
    LevelZero(std::string filename);
    Block* genBlock() override;
    Block* genBlock(const char type) override;

  private:
    const int levelGenerated = 0;
};

#endif
