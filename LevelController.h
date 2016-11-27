#include <string>
#include "level.h"

class LevelController{
  Level * currentLevel;

  public:
    LevelController(int level);
    void changeLevel(int levelNum);
    void setFileName(std::string fileName);
    const Level * getLevel();
}

