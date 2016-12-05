#include <string>
#include "LevelController.h"
#include "LevelZero.h"
#include "LevelOne.h"
#include "LevelTwo.h"
#include "LevelThree.h"
#include "LevelFour.h"
#include <iostream>

#define DEBUG 1

using namespace std;

LevelController::LevelController(const int level) {;
  changeLevel(level);  
}

void LevelController::changeLevel(const int levelNum) {
  if (currentLevel) delete currentLevel;

  switch(levelNum) {
    case 0: currentLevel = new LevelZero{"sequence2.txt"};
      break;
    case 1: currentLevel = new LevelOne{};
      break;
    case 2: currentLevel = new LevelTwo{};
      break;
    case 3: currentLevel = new LevelThree{};
      break;
    case 4: currentLevel = new LevelFour{};
      break;
  }
}

void LevelController::setFilename(const std::string fileName){
  if(DEBUG) cout << "setting filename" << endl;
  currentLevel->setFilename(fileName);
}

Level *const LevelController::getLevel(){
  return currentLevel;
}


