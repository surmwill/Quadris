#ifndef LEVEL_H
#define LEVEL_H 1

#include <string>
#include <vector>
#include "BlockLib.h"

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
    virtual std::vector<char> genBlock() = 0;
    virtual std::vector<char> genBlock() = 0;
    ~Level() = 0;
};

#endif
