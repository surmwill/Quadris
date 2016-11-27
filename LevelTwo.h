#ifndef LEVEL_TWO_H
#define LEVEL_TWO_H 1

#include <vector>
#include <string>
#include "Level.h"

using namespace std;

class LevelTwo: public Level {  
  public:
    std::vector<char> genBlock() override;
    std::vector<char> genBlockWithType(char type) override;
};

#endif
