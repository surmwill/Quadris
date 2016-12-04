#include "LevelZero.h"
#include "Level.h"
#include <vector> 
#include <string> 
#include <fstream>
#include "Block.h"

using namespace std;

LevelZero::LevelZero(std::string fileName) {
  setFilename(fileName);
}

Block* LevelZero::genBlock() {
  if(!getSeqFile().is_open() || getSeqFile().eof()) return nullptr;
  
  string symbol;
  getSeqFile() >> symbol;
  if(symbol.length() > 1) return nullptr;
  else return new Block(getBlockLib()->getBlockLayout(symbol[0]), 0); 
}

Block* LevelZero::genBlock(char type) {
  vector vector <<int>
  vector <int> flattenedLayout; 
  return new Block{getBlockLib()->getBlockLayout(type), 0};
}
