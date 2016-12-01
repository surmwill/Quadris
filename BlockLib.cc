#include "BlockLib.h"
#include <vector>
#include <map>

using namespace std;

BlockLib::BlockLib() {
  layoutMap.emplace("i", &iBlock);
  layoutMap.emplace("j", &jBlock);
  layoutMap.emplace("l", &lBlock);
  layoutMap.emplace("o", &oBlock);
  layoutMap.emplace("s", &sBlock);
  layoutMap.emplace("z", &zBlock);
}

vector <char> getBlockLayout(char blockType) {
  auto iter = layoutMap.find(blockType);
  return ((*iter)->second)();
}

vector <char> BlockLib::iBlock() {
  vector <char> design;
  int i;

  for(i = 0; i < 4; i++) {design.emplace_back(' ');}
  for(i = 0; i < 4; i++) {design.emplace_back('I');}
  for(i = 0; i < 4; i++) {design.emaplce_back(' ');}
  for(i = 0; i < 4; i++) {design.emaplce_back(' ');}

  return design;
}

vector <char> BlockLib::jBlock() {
  vector <char> design;
  int i;
  
  design.emplace_back('J');
  for(i = 0; i < 3; i++) {design.emplace_back(' ');}
  for(i = 0; i < 3; i++) {design.emplace_back('J');}
  design.emplace_back(' '); //lines 1 and 2 completed

  for(i = 0; i < 4; i++) {design.emplace_back('I');}
  for(i = 0; i < 4; i++) {design.emaplce_back(' ');}

  return design;
}

vector <char> BlockLib::lBlock() {
  vector <char> design;
  int i = 0;
  
  for(i = 0; i < 3; i++) {design.emplace_back(' ');}
  design.emplace_back('L');
  for(i = 0; i < 3; i++) {design.emplace_back('L');}
  design.emplace_back(' '); //lines 1 and 2 complete

  for(i = 0; i < 4; i++) {design.emplace_back(' ');}
  for(i = 0; i < 4; i++) {design.emplace_back(' ');} 

  return design;
}

vector <char> BlockLib::oBlock() {
  vector <char> design;
  int i = 0;

  for(i = 0; i < 2; i++) {design.emplace_back('O');}
  for(i = 0; i < 2; i++) {design.emplace_back(' ');}
  for(i = 0; i < 2; i++) {design.emplace_back('O');}
  for(i = 0; i < 2; i++) {design.emplace_back(' ');} //lines 1 and 2 complete

  for(i = 0; i < 4; i++) {design.emplace_back(' ');}
  for(i = 0; i < 4; i++) {design.emplace_back(' ');}
  return design;
}


vector <char> BlockLib::sBlock() {
  vector <char> design;
  int i = 0;

  for(i = 0; i < 2; i++) {design.emplace_back(' ');}
  for(i = 0; i < 2; i++) {design.emplace_back('S');}
  for(i = 0; i < 2; i++) {design.emplace_back('S');}
  for(i = 0; i < 2; i++) {design.emplace_back(' ');} //lines 1 and 2 complete

  for(i = 0; i < 4; i++) {design.emplace_back(' ');}
  for(i = 0; i < 4; i++) {design.emplace_back(' ');}

  return design;
}

vector <char> BlockLib::zBlock() {
  vector <char> design;
  int i = 0;

  for(i = 0; i < 2; i++) {design.emplace_back('Z');}
  for(i = 0; i < 2; i++) {design.emplace_back(' ');}
  for(i = 0; i < 2; i++) {design.emplace_back(' ');}
  for(i = 0; i < 2; i++) {design.emplace_back('Z');} //lines 1 and 2 complete

  for(i = 0; i < 4; i++) {design.emplace_back(' ');}
  for(i = 0; i < 4; i++) {design.emplace_back(' ');}

  return design;
}

vector <char> BlockLib::tBlock() {
  vector <char> design;
  int i = 0;

  for(i = 0; i < 3; i++) {design.emplace_back('T');}
  for(i = 0; i < 2; i++) {design.emplace_back(' ');}
  design.emplace_back('T');
  for(i = 0; i < 2; i++) {design.emplace_back(' ');} //lines 1 and 2 complete

  for(i = 0; i < 4; i++) {design.emplace_back(' ');}
  for(i = 0; i < 4; i++) {design.emplace_back(' ');}

  return design;
}
