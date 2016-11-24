#include <string>
#include <vector>

using namespace std;

string Level::getFilename(){
  return "";
}

virtual vector<char> Level::genBlock();

virtual vector<char> Level::genBlock(std::char type); 

void Level::setFileName();

int Level::getLevel(){
  return levelNum;
}
