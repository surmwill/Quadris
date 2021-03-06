#ifndef INFO_H
#define INFO_H

struct Info {
  Info(char symbol, int blockSize, int levelGenerated, int row, int col);

  char symbol; //the Cell's symbol
  int blockSize; //the amount of Cells currently making up the block
  int levelGenerated; //the level the block was generated in
  int row, col; //the cell's coordinates in the grid
  bool set; // tells us whether or not the block has been dropped in the board
};

#endif
