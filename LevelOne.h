#ifndef LEVEL_ONE_H
#define LEVEL_ONE_H 1

#include <vector>
#include <string>
#include "Level.h"

using namespace std;

class LevelOne: public Level {  
  public:
    std::vector<char> genBlock() override;
    std::vector<char> genBlockWithType(char type) override;
};

#endif
