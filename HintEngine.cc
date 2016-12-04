#include "HintEngine.h"
#include "BlockController.h"
#include <vector>
#include <memory>

HintEngine::HintEngine(shared_ptr <BlockController> bc): bc(bc) {}

vector <vector <int>> HintEngine::hint() {
}
