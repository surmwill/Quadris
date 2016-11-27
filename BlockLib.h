#ifndef BLOCK_LIB_H
#define BLOCK_LIB_H 1

#include <vector>
#include <map>

class BlockLib {
 public:
   BlockLib();
   std::vector <char> getBlockLayout(char blockType);
 private:
   std::vector <char> iBlock();
   std::vector <char> jBlock();
   std::vector <char> lBlock();
   std::vector <char> oBlock();
   std::vector <char> sBlock();
   std::vector <char> zBlock();
   std::vector <char> tBlock();

   //Function pointer with return type vec <char>, paramter char, and generalized name of BlockLayoutFn
   typedef std::vector <char> (*BlockLayoutFn)(char);
   std::map <char, BlockLayoutFn> layoutMap; //allowed to do since every fn mapped has the same paramters and return type
};

#endif
