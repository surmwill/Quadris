#include "Info.h"

using namespace std;

Info::Info(char symbol, int blockSize, int levelGenerated, int row, int col): symbol{symbol}, blockSize{blockSize}, levelGenerated{levelGenerated} {
  coords.push_back(row);
  coords.push_back(col);
}
