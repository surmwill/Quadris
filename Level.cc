#include "Level.h"
#include "BlockLib.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

Level::~Level() {};

void Level::setFilename(const string filename) {
  if(goodFile(filename)) {
    if(seqFile.is_open()) seqFile.close();
    seqFile.open(filename);
  }
}

BlockLib * Level::getBlockLib() {
  return &blockLib;
}

bool Level::goodFile(const std::string filename) {
  if(filename.length() < 1) return false;

  ofstream myfile{filename};
  if(myfile.is_open()) return true;
  else return false;
}

ofstream & Level::getSeqFile() {
  return seqFile;
}
