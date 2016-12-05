#include "BlockLib.h"
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <cstdlib>

using namespace std;

BlockLib::BlockLib() {}

vector <vector <char>> BlockLib::getBlockLayout(char blockType) const {
  switch(blockType) {
    case 'I' : return iBlock();
    case 'J' : return jBlock();
    case 'L' : return lBlock();
    case 'O' : return oBlock();
    case 'S' : return sBlock();
    case 'Z' : return zBlock();
    case 'T' : return tBlock();
  };

  int randNum = rand() % 7 + 1;
  switch(randNum) {
   case 1 : return getBlockLayout('I');
   case 2 : return getBlockLayout('J');
   case 3 : return getBlockLayout('L');
   case 4 : return getBlockLayout('O');
   case 5 : return getBlockLayout('S');
   case 6 : return getBlockLayout('Z');
   case 7 : return getBlockLayout('T');
   default : return getBlockLayout('T'); //to silnce the warnings, this will never be called
 };
} 

vector <char> BlockLib::getFlattenedBlockLayout(char blockType) const {
  vector <char> flatDesign;
  vector <vector <char>> design = getBlockLayout(blockType);

  for(auto &row: design) {
    for(auto &col: row) {
      flatDesign.emplace_back(col);
    }
  }
  return flatDesign;
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

vector <vector <char>> BlockLib::jBlock() const {
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
  
  for(i = 0; i < 2; i++) {designRow.emplace_back(' ');}
  designRow.emplace_back('L');
  designRow.emplace_back(' ');
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

  designRow.emplace_back(' ');
  for(i = 0; i < 2; i++) {designRow.emplace_back('S');}
  designRow.emplace_back(' ');
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
  vector <vector <char>> design;
  vector <char> designRow;

  int i = 0;

  for(i = 0; i < 2; i++) {designRow.emplace_back('Z');}
  for(i = 0; i < 2; i++) {designRow.emplace_back(' ');}
  design.emplace_back(designRow);
  designRow.clear();

  designRow.emplace_back(' ');
  for(i = 0; i < 2; i++) {designRow.emplace_back('Z');} 
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

vector <vector <char>> BlockLib::tBlock() const {
  vector <vector <char>> design;
  vector <char> designRow;

  int i = 0;

  for(i = 0; i < 3; i++) {designRow.emplace_back('T');}
  designRow.emplace_back(' ');
  design.emplace_back(designRow);
  designRow.clear();

  designRow.emplace_back(' ');
  designRow.emplace_back('T');
  for(i = 0; i < 2; i++) designRow.emplace_back(' ');
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 4; i++) designRow.emplace_back(' ');
  design.emplace_back(designRow);
  designRow.clear();

  for(i = 0; i < 4; i++) designRow.emplace_back(' ');
  design.emplace_back(designRow);
  designRow.clear();
  
  return design;
}
