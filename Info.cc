#include "Info.h"

using namespace std;

Info::Info(char symbol, int blockSize, int levelGenerated, int row, int col): symbol{symbol}, blockSize{blockSize}, levelGenerated{levelGenerated},
  row{row}, col{col}, set{false} {}
