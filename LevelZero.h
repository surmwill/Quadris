#include <vector>
#include <string>


class LevelZero: public Level {
  
  public:
    LevelZero(std:string filename);
    std::vector<char> genBlock();
}
