#ifndef INFO_H
#define INFO_H 1

#include <vector>

struct Info {
  int blockSize; //the amount of Cells currently making up the block
  std::vector <int> coords; //the coordinates of the Cell
  char symbol; //the Cell's symbol
  int levelGenerated; //the level the block was generated in
};

#endif
