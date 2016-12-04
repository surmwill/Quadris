#ifndef BLOCK_LIB_H
#define BLOCK_LIB_H 1

#include <vector>
#include <map>

class BlockLib {
 public:
   BlockLib();
   std::vector <std::vector <char>> getBlockLayout(char blockType) const; //returns the the desired block layout given a type of block

 private:
   std::vector <std::vector <char>> iBlock() const; //returns a 2D vector of 4x4 chars, that represents the design of an I block
   std::vector <std::vector <char>> jBlock() const; //returns a 2D vector of 4x4 chars, that represents the design of an J block
   std::vector <std::vector <char>> lBlock() const; //returns a 2D vector of 4x4 chars, that represents the design of an L block
   std::vector <std::vector <char>> oBlock() const; //returns a 2D vector of 4x4 chars, that represents the design of an O block
   std::vector <std::vector <char>> sBlock() const; //returns a 2D vector of 4x4 chars, that represents the design of an S block
   std::vector <std::vector <char>> zBlock() const; //returns a 2D vector of 4x4 chars, that represents the design of an Z block
   std::vector <std::vector <char>> tBlock() const; //returns a 2D vector of 4x4 chars, that represents the design of an T block

   typedef std::vector <std::vector <char>> (*BlockLayoutFn)(char); //Function pointer with return type <vector <vector <char>>, paramter char, and generalized name of BlockLayoutFn
   std::map <char, BlockLayoutFn> layoutMap; //Maps a function that returns a block design to a type of block
};

#endif
