#ifndef LEVEL_FOUR_H
#define LEVEL_FOUR_H 1

#include <vector>
#include <string>
#include "Level.h"

class Block;

using namespace std;

class LevelFour: public Level {  
    int blockNum = 0;

  public:
    Block* genBlock() override;
    Block* genBlock(const char type) override;
};

#endif
