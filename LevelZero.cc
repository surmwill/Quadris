#include "LevelZero.h"
#include "Level.h"
#include <vector> 
#include <string> 
#include <fstream>
#include "Block.h"
#include <iostream>

#define DEBUG 0

using namespace std;

LevelZero::LevelZero(std::string fileName) {
  if(DEBUG == 1) cout << "LevelZero::LevelZero" << endl;
  setFilename(fileName);
}

Block* LevelZero::genBlock() {
  if(DEBUG == 1) cout << "LevelZero::genBlock()" << endl;
  if(!getSeqFile().is_open() || getSeqFile().eof()) return genBlock('Q'); //Q is a dummy value. Since we have no Q block our Block lib will generate a random block we do have instead
  
  string symbol;
  getSeqFile() >> symbol;
  if(symbol.length() > 1) return genBlock('Q');
  else return genBlock(symbol[0]); 
}

Block* LevelZero::genBlock(const char type) {
  if(DEBUG == 1) {
    cout << "getting the flattened block" << endl;
    vector <char> temp = getBlockLib().getFlattenedBlockLayout(type);
    for(auto &n : temp) cout << n << endl;
  }
  Block * b = new Block{getBlockLib().getFlattenedBlockLayout(type), levelGenerated};
  if(DEBUG == 1) cout << "returning new block" << endl;
  return b;
}
