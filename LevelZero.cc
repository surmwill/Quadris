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
  else return new Block{getBlockLib()->getFlattenedBlockLayout(symbol[0]), levelGenerated}; 
}

Block* LevelZero::genBlock(const char type) {
  return new Block{getBlockLib()->getFlattenedBlockLayout(type), levelGenerated};
}
