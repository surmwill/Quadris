#ifndef LEVEL_THREE_H
#define LEVEL_THREE_H 1

#include <vector>
#include <string>
#include "Level.h"

using namespace std;

class LevelThree: public Level {  
  public:
    Block* genBlock() override;
    Block* genBlock(char type) override;
};

#endif
