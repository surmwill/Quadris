#ifndef LEVEL_THREE_H
#define LEVEL_THREE_H 1

#include <vector>
#include <string>
#include "Level.h"

using namespace std;

class LevelThree: public Level {  
  public:
    std::vector<char> genBlock() override;
    std::vector<char> genBlockWithType(char type) override;
};

#endif
