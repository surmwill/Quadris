#ifndef LEVEL_FOUR_H
#define LEVEL_FOUR_H 1

#include <vector>
#include <string>
#include "Level.h"

using namespace std;

class LevelFour: public Level {  
  public:
    std::vector<char> genBlock() override;
    std::vector<char> genBlockWithType(char type) override;
};

#endif
