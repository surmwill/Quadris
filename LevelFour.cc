#include "LevelFour.h"
#include "Level.h"
#include "HeavyBlock.h"
#include "DirectedBlock.h"
#include <vector> 
#include <string> 

using namespace std;

Block* LevelFour::genBlock() {
  // create a model for the probability breakdown
  vector<char> symbolProbability;

  // I block probability (1/9)
  symbolProbability.push_back('I');

  // J block probability (1/9)
  symbolProbability.push_back('J');

  // L block probability (1/9)
  symbolProbability.push_back('L');

  // O block probability (1/9)
  symbolProbability.push_back('O');

  // S block probability (2/9)
  symbolProbability.push_back('S');
  symbolProbability.push_back('S');

  // Z block probability (2/9)
  symbolProbability.push_back('Z');
  symbolProbability.push_back('Z');

  // T block probability (1/9)
  symbolProbability.push_back('T');

  int randInt = rand() % symbolProbability.size();

  return genBlock(symbolProbability[randInt]);
 }

Block* LevelFour::genBlock(const char type) {
  if ((blockNum % 5) == 0){
    Block *dBlock = new DirectedBlock{getBlockLib().getFlattenedBlockLayout(type), 4};
    return dBlock;
  }

  Block *hBlock = new HeavyBlock{getBlockLib().getFlattenedBlockLayout(type), 4};
  return hBlock;
}

