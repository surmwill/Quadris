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
    BlockLib * getBlockLib(); 

  public:
    virtual Block* genBlock() = 0;
    virtual Block* genBlock(char type) = 0;
    virtual ~Level() = 0;
    void setFilename(std::string fileName);
};

#endif
