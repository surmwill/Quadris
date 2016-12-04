#ifndef INFO_H
#define INFO_H 1

#include <vector>

struct Info {
  Info(char symbol, int blockSize, int levelGenerated, int row, int col);
  char symbol; //the Cell's symbol
  int blockSize; //the amount of Cells currently making up the block
  int levelGenerated; //the level the block was generated in
  std::vector <int> coords; //the coordinates of the Cell
};

#endif
