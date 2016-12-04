#ifndef LEVEL_CONTROLLER_H
#define LEVEL_CONTROLLER_H 1

#include <string>

class Level;

class LevelController{
  private:
    Level * currentLevel;

  public:
    LevelController(int level);
    void changeLevel(int levelNum);
    void setFileName(std::string fileName);
    Level * const getLevel(); //2 consts: Won't modify where it's pointing and what it's pointing at
};

#endif
