#ifndef BLOCK_LIB_H
#define BLOCK_LIB_H 1

#include <vector>
#include <map>

class BlockLib {
 public:
   BlockLib();
   std::vector <std::vector <char>> getBlockLayout(char blockType); //returns the the desired block layout 

 private:
   std::vector <std::vector <char>> iBlock();
   std::vector <std::vector <char>> jBlock();
   std::vector <std::vector <char>> lBlock();
   std::vector <std::vector <char>> oBlock();
   std::vector <std::vector <char>> sBlock();
   std::vector <std::vector <char>> zBlock();
   std::vector <std::vector <char>> tBlock();

   //Function pointer with return type vec <char>, paramter char, and generalized name of BlockLayoutFn
   typedef std::vector <std::vector <char>> (*BlockLayoutFn)(char);
   std::map <char, BlockLayoutFn> layoutMap; //allowed to do since every fn mapped has the same paramters and return type
};

#endif
