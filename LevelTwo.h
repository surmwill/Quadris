#ifndef LEVEL_TWO_H
#define LEVEL_TWO_H 1

#include <vector>
#include <string>
#include "Level.h"

class Block;

using namespace std;

class LevelTwo: public Level {  
  public:
    Block* genBlock() override;
    Block* genBlock(const char type) override;
};

#endif
