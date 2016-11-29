#ifndef HINT_ENGINE_H
#define HINT_ENGINE_H 1

#include <vector>

class BlockController;

class HintEngine {
 public:
  HintEngine(BlockController *bc);
  std::vector <std::vector <int>> hint();
 private:
  BlockController *bc;
};

#endif
