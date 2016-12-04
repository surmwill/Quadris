#include "HintEngine.h"
#include "BlockController.h"
#include <vector>
#include <memory>

using namespace std;

HintEngine::HintEngine(shared_ptr <BlockController> bc): bc(bc) {}

vector <vector <int>> HintEngine::hint() {
  vector <vector <int>> coords;
  return coords;
}
