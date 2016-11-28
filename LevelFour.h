#ifndef LEVEL_FOUR_H
#define LEVEL_FOUR_H 1

#include <vector>
#include <string>
#include "Level.h"

class Block;

using namespace std;

class LevelFour: public Level {  
  public:
    Block* genBlock() override;
    Block* genBlock(char type) override;
};

#endif
