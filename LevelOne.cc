#include "LevelOne.h"
#include "Level.h"
#include <vector> 
#include <string> 
#include <cstdlib>
#include "Block.h"

using namespace std;

Block* LevelOne::genBlock() {
  vector <char> symbolProbability;
  
  //S block 1/12
  symbolProbability.emplace_back('S');

  //Z block 1/12
  symbolProbability.emplace_back('Z');

  
  //The rest of the blocks have probability 2/12
  for(int i = 0; i < 2; i++) symbolProbability.emplace_back('I');
  for(int i = 0; i < 2; i++) symbolProbability.emplace_back('J');
  for(int i = 0; i < 2; i++) symbolProbability.emplace_back('L');
  for(int i = 0; i < 2; i++) symbolProbability.emplace_back('O');
  for(int i = 0; i < 2; i++) symbolProbability.emplace_back('T');

  int randInt = rand() % symbolProbability.size();
  return genBlock(symbolProbability[randInt]);
}

Block* LevelOne::genBlock(const char type) {
  return new Block{getBlockLib()->getFlattenedBlockLayout(type), levelGenerated};
}
