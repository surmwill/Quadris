#include <vector>
#include <string>
#include "Level.h"

class LevelZero: public Level {  
  public:
    LevelZero(std::string filename);
    std::vector<char> genBlock();
}
