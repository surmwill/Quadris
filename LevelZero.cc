#include "LevelZero.h"
#include "Level.h"
#include <vector> 
#include <string> 
#include <fstream>
#include "Block.h"
#include <iostream>

using namespace std;

LevelZero::LevelZero(std::string fileName) {
  setFilename(fileName);
}

Block* LevelZero::genBlock() {
  if(!getSeqFile().is_open() || getSeqFile().eof()) return genBlock('Q'); //Q is a dummy value. Since we have no Q block our Block lib will generate a random block we do have instead
  
  string symbol;
  getSeqFile() >> symbol;
  if(symbol.length() > 1) return genBlock('Q');
  else return genBlock(symbol[0]); 
}

Block* LevelZero::genBlock(const char type) {
  Block * b = new Block{getBlockLib().getFlattenedBlockLayout(type), levelGenerated};
  return b;
}
