#include "Level.h"
#include "BlockLib.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#define DEBUG 1

using namespace std;

Level::~Level() {};

void Level::setFilename(const string filename) {
  bool openable = goodFile(filename);
  if(openable) {
    if(seqFile.is_open()) seqFile.close();
    seqFile.open(filename);
  }
  if(DEBUG) cout << filename << " is a good file" << endl;
}

const BlockLib & Level::getBlockLib() {
  return blockLib;
}

bool Level::goodFile(const std::string filename) {
  if(filename.length() < 1) return false;

  ifstream myfile{filename};
  if(myfile.is_open()) {
    myfile.close();
    return true;
  }
  else return false;
}

ifstream & Level::getSeqFile() {
  return seqFile;
}
