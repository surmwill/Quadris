#ifndef LEVEL_H
#define LEVEL_H 1

#include <string>
#include <vector>
#include <fstream>
#include "BlockLib.h"

class Block;

class Level{
  private:
    std::ofstream seqFile; //the file which contains the sequence of commands
    int levelNum; // the level number
    BlockLib blockLib; //the block library
    
    bool goodFile(const std::string filename); //returns true if we can open the file for input
 	
  protected:
    std::ifstream & getSeqFile(); //returns the seqFile
    BlockLib * getBlockLib();  //returns the BlockLib

  public:
    virtual Block* genBlock() = 0; //generates a random block based on the rules of the level/game
    virtual Block* genBlock(char type) = 0; //generates a block with type char
    virtual ~Level() = 0; 
    void setFilename(const std::string fileName); //sets the seqFile to open the filename if the file can be opened
};

#endif
