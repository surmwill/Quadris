#ifndef LEVEL_CONTROLLER_H
#define LEVEL_CONTROLLER_H 1

#include <string>

class Level;
class LevelZero;
class LevelOne;
class LevelTwo;
class LevelThree;
class LevelFour;

class LevelController{
  private:
    Level * currentLevel;

  public:
    LevelController(const int level);
    void changeLevel(const int levelNum);
    void setFilename(const std::string fileName);
    Level * const getLevel(); //2 consts: Won't modify where it's pointing and what it's pointing at
};

#endif
