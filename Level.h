#ifndef LEVEL_H
#define LEVEL_H 1

#include <string>
#include <vector>
#include "BlockLib.h"

class Block;

class Level{
  private:
    std::string fileName;
    int levelNum;
    BlockLib blockLib;	

  protected:
    Level();
    void setFilename(std::string fileName);
    BlockLib * getBlockLib(); 

  public:
    Block* genBlock() = 0;
    Block* genBlock(char type) = 0;
    ~Level() = 0;
};

#endif
