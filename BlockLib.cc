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
}

vector <char> BlockLib::jBlock() {
}

vector <char> BlockLib::lBlock() {
}

vector <char> BlockLib::oBlock() {
}

vector <char> BlockLib::sBlock() {
}

vector <char> BlockLib::zBlock() {
}

