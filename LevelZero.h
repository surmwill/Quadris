#ifndef LEVEL_ZERO_H
#define LEVEL_ZERO_H 1

#include <vector>
#include <string>
#include "Level.h"

class LevelZero: public Level {  
  public:
    LevelZero(std::string filename);
    std::vector<char> genBlock() override;
    std::vector<char> genBlockWithType(char type) override;
};

#endif
