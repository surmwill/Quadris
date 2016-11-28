#include "DirectedBlock.h"
#include "Block.h"
#include <vector>

using namespace std;

DirectedBlock::DirectedBlock(vector <char> blockDesign, int levelGenerated, int blockSize):
  Block{blockDesign, levelGenerated, blockSize} {}

void DirectedBlock::left() {
}

void DirectedBlock::right() {
}

void DirectedBlock::rotatecw() {
}

void DirectedBlock::rotatecc() {
}

bool DirectedBlock::autoDrop() {
}

bool DirectedBlock::drop() {
}

bool DirectedBlock::down() {
}

