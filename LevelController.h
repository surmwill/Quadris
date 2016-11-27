#include <string>
#include "level.h"

class LevelController{
  private:
    Level * currentLevel;

  public:
    LevelController(int level);
    void changeLevel(int levelNum);
    void setFileName(std::string fileName);
    const Level * const getLevel(); //2 consts: Won't modify where it's pointing and what it's pointing at
};
