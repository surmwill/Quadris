#include <string>
#include "levelController.h"

using namespace std;

LevelController::LevelController(int level) {
  changeLevel(level);  
}

void LevelController::changeLevel(int levelNum){
  switch(levelNum) {
    case 0: currentLevel = new LevelZero{"sequence.txt"};
      break;
    case 1: currentLevel = new LevelOne{};
      break;
    case 2: currentLevel = new LevelTwo{};
      break;
    case 3: currentLevel = new LevelThree{};
      break;
    case 4: currentLEvel = new LevelFour{};
      break;
  }
}

void LevelController::setFileName(std::string fileName){
  currentLevel->setFileName(fileName);
}

const Level * LevelController::getLevel(){
  return currentLevel;
}


