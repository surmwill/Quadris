#ifndef HINT_ENGINE_H
#define HINT_ENGINE_H 1

#include <vector>
#include <memory>

class BlockController;

class HintEngine {
 public:
  HintEngine(std::shared_ptr <BlockController> bc);
  std::vector <std::vector <int>> hint();

 private:
  std::shared_ptr <BlockController> bc;
};

#endif
