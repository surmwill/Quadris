#include "Level.h"
#include <string>
#include <vector>

using namespace std;

Level::Level(): fileName{""}: 

Level::~Level() {};

void Level::setFilename(string fileName){
  this->fileName = fileName;
}
