#include "LevelZero.h"
#include "Level.h"
#include <vector> 
#include <string> 
#include "Block.h"

using namespace std;

LevelZero::LevelZero(std::string fileName) {
  setFilename(fileName);
}

Block* LevelZero::genBlock() {
}

Block* LevelZero::genBlock(char type) {
}

