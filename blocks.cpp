#include "blocks.h"

Grid::Grid(int nr, int nc) {
  this->nr = nr;
  this->nc = nc;
  cells = new Cell [nr * nc];
}

Grid::Grid(const Grid& grid) {
  cells = NULL;
  *this = grid;
}

Grid::~Grid() {
  if (cells) delete [] cells;
}

Grid& Grid::operator=(const Grid& grid) {
  if (cells) delete [] cells;
  nr = grid.nr;
  nc = grid.nc;
  return *this;
}

Block::Block(int nr, int nc) : Grid(nr, nc) {
  setPivot(nr / 2, nc / 2);
}

Block::Block(const Grid& grid) : Grid(grid) { }
  
void Block::map(const std::string& cells, const std::string& map, int r, int c) {
  setPivot(r, c);

  char charMap[256];
  memset(charMap, 0, 256);
  for (int i = 0; i < map.size(); i++)
    charMap[map[i]] = i;

  for (int r = 0; r < rows(); r++)
    for (int c = 0; c < cols(); c++)
      set(r, c, charMap[cells[r * cols() + c]]);
}

Block Block::leftRotate() const {
  //TODO
  return *this;
}

Block Block::rightRotate() const {
  //TODO
  return *this;
}

bool Block::inBounds(const Grid& grid, int r, int c) const {
  //TODO
  return 0;
}

bool Block::collides(const Grid& grid, int r, int c) const {
  if (!inBounds(grid, r, c)) return 1;
  
  for (int r1 = 0; r1 < rows(); r1++)
    for (int c1 = 0; c1 < cols(); c1++)
      if (at(r1, c1) && grid.at(r - pr, c - pc)) return 0;

  return 1;
}

FallingBlock::FallingBlock() : Block() {
  setTicks(1);
  setPosition(0, 0);
}

FallingBlock::FallingBlock(const Block& block, int ticks = 1) : Block(block) {
  setTicks(ticks);
  setPosition(0, 0);
}

void FallingBlock::getDisplayPosition(const Grid& grid, float& r, float& c) const;

void FallingBlock::tick() {
  if (willFall()) {
    r++;
    currentTicks = 0;
  }
  else
    currentTicks++;
}

bool FallingBlock::landed(const Grid& grid) const {
  //TODO
  return 0;
}

void FallingBlock::plant(Grid& grid) const {
  //TODO
}
