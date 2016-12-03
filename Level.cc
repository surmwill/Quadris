#include "Level.h"
#include <string>
#include <vector>
#include "BlockLib.h"

using namespace std;

Level::Level(): fileName{""}:

Level::~Level() {};

void Level::setFilename(string fileName){
  this->fileName = fileName;
}

BlockLib * Level::getBlockLib() {
  return &blockLib;
}
