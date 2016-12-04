#include "LevelTwo.h"
#include "Level.h"
#include "Block.h"
#include <vector> 
#include <string> 

using namespace std;

Block* LevelTwo::genBlock() {
  // create a model for the probability breakdown
  vector<char> symbolProbability;

  // I block probability (1/7)
  symbolProbability.push_back('I');

  // J block probability (1/7)
  symbolProbability.push_back('J');

  // L block probability (1/7)
  symbolProbability.push_back('L');

  // O block probability (1/7)
  symbolProbability.push_back('O');

  // S block probability (1/7)
  symbolProbability.push_back('S');

  // Z block probability (1/7)
  symbolProbability.push_back('Z');

  // T block probability (1/7)
  symbolProbability.push_back('T');

  int randInt = rand() % symbolProbability.size();

  return genBlock(symbolProbability[randInt]);
 }

Block* LevelTwo::genBlock(char type) {
  Block *block = new Block((getBlockLib()->getFlattenedBlockLayout(type)), 2);
  return block;
}
