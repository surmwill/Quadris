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

vector <vector <char>> BlockLib::getBlockLayout(char blockType) const {
  auto iter = layoutMap.find(blockType);
  return (iter->second)();
} 

vector <vector <char>> BlockLib::iBlock() const {
  vector <vector <char>> design;
  vector <char> designRow;
  int i;
  
  //row 1
  for(i = 0; i < 4; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  //row 2
  for(i = 0; i < 4; i++) {designRow.emplace_back('I');}
  design.emplace_back(designRow);
  designRow.clear();

  //row 3
  for(i = 0; i < 4; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  //row 4
  for(i = 0; i < 4; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  return design;
}

vector <vector <<char> BlockLib::jBlock() const {
  vector <vector <char>> design;
  vector <char> designRow;
  int i;
  
  //row 1
  designRow.emplace_back('J');
  for(i = 0; i < 3; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  // row 2
  for(i = 0; i < 3; i++) {designRow.emplace_back('J');}
  designRow.emplace_back(' '); 
  design.emplace_back(designRow);
  designRow.clear();

  // row 3
  for(i = 0; i < 4; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  // row 4
  for(i = 0; i < 4; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  return design;
}

vector <vector <char>> BlockLib::lBlock() const {
  vector <vector <char>> design;
  vector <char> designRow;
  int i = 0;
  
  for(i = 0; i < 3; i++) {designRow.emplace_back(' ');}
  designRow.emplace_back('L');
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 3; i++) {designRow.emplace_back('L');}
  designRow.emplace_back(' '); 
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 4; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 4; i++) {designRow.emplace_back(' ');} 
  design.emplace_back(designRow);
  designRow.clear();

  return design;
}

vector <vector <char>> BlockLib::oBlock() const {
  vector <vector <char>> design;
  vector <char> designRow;

  int i = 0;

  for(i = 0; i < 2; i++) {designRow.emplace_back('O');}
  for(i = 0; i < 2; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 2; i++) {designRow.emplace_back('O');}
  for(i = 0; i < 2; i++) {designRow.emplace_back(' ');} 
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 4; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 4; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  return design;
}


vector <vector <char>> BlockLib::sBlock() const {
  vector <vector <char>> design;
  vector <char> designRow;

  int i = 0;

  for(i = 0; i < 2; i++) {designRow.emplace_back(' ');}
  for(i = 0; i < 2; i++) {designRow.emplace_back('S');}
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 2; i++) {designRow.emplace_back('S');}
  for(i = 0; i < 2; i++) {designRow.emplace_back(' ');} 
  design.emplace_back(designRow);
  designRow.clear();


  for(i = 0; i < 4; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 4; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  return design;
}

vector <vector <char>> BlockLib::zBlock() const {
  vector <vector <char> design;
  vector <char> designRow;

  int i = 0;

  for(i = 0; i < 2; i++) {designRow.emplace_back('Z');}
  for(i = 0; i < 2; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 2; i++) {designRow.emplace_back(' ');}
  for(i = 0; i < 2; i++) {designRow.emplace_back('Z');} 
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 4; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 4; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  return design;
}

vector <vector <char>> BlockLib::tBlock() const {
  vector vector <char>> design;
  vector <char> designRow;

  int i = 0;

  for(i = 0; i < 3; i++) {designRow.emplace_back('T');}
  designRow.emplace_back(' ');
  design.emplace_back(designRow);
  designRow.clear();

  designRow.emplace_back(' ');
  designRow.emplace_back('T');
  for(i = 0; i < 2; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 4; i++) {design.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 4; i++) {design.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  return design;
}
