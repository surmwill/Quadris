#ifndef LEVEL_ONE_H
#define LEVEL_ONE_H 1

#include <vector>
#include <string>
#include "Level.h"

class Block;

using namespace std;

class LevelOne: public Level {  
  public:
    Block* genBlock() override;
    Block* genBlock(char type) override;
};

#endif
