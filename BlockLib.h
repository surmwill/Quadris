#ifndef BLOCK_LIB_H
#define BLOCK_LIB_H

#include <vector>

class BlockLib {
 public:
   BlockLib();
   std::vector <std::vector <char>> getBlockLayout(char blockType) const; //returns the desired block layout given a type of block
   std::vector <char> getFlattenedBlockLayout(char blockType) const; //returns the desired block layout in a 1d vector

 private:
   std::vector <std::vector <char>> iBlock() const; //returns a 2D vector of 4x4 chars, that represents the design of an I block
   std::vector <std::vector <char>> jBlock() const; //returns a 2D vector of 4x4 chars, that represents the design of an J block
   std::vector <std::vector <char>> lBlock() const; //returns a 2D vector of 4x4 chars, that represents the design of an L block
   std::vector <std::vector <char>> oBlock() const; //returns a 2D vector of 4x4 chars, that represents the design of an O block
   std::vector <std::vector <char>> sBlock() const; //returns a 2D vector of 4x4 chars, that represents the design of an S block
   std::vector <std::vector <char>> zBlock() const; //returns a 2D vector of 4x4 chars, that represents the design of an Z block
   std::vector <std::vector <char>> tBlock() const; //returns a 2D vector of 4x4 chars, that represents the design of an T block
};

#endif
