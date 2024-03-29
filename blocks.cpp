#include "blocks.h"
#include <cstring>

Grid::Grid(int nr, int nc) {
  this->nr = nr;
  this->nc = nc;
  cells = new Cell [nr * nc];
  memset(cells, 0, nr * nc * sizeof(Cell));
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
  cells = new Cell [nr * nc];
  memcpy(cells, grid.cells, nr * nc * sizeof(Cell));
  return *this;
}

Block::Block(int nr, int nc) : Grid(nr, nc) {
  setPivot(nr / 2, nc / 2);
}

Block::Block(const Grid& grid) : Grid(grid) { }
  
const Block& Block::map(const std::string& cells, const std::string& map, int r, int c) {
  setPivot(r, c);

  char charMap[256];
  memset(charMap, 0, 256);
  for (int i = 0; i < map.size(); i++)
    charMap[map[i]] = i;

  for (int r = 0; r < rows(); r++)
    for (int c = 0; c < cols(); c++)
      set(r, c, charMap[cells[r * cols() + c]]);

  return *this;
}

Block Block::leftRotate() const {
  Block rotated(nc, nr);
  for (int r = 0; r < rotated.rows(); r++)
    for (int c = 0; c < rotated.cols(); c++)
      rotated.set(r, c, at(cols() - c - 1, r));
  return *this;
}

Block Block::rightRotate() const {
  Block rotated(nc, nr);
  for (int r = 0; r < rotated.rows(); r++)
    for (int c = 0; c < rotated.cols(); c++)
      rotated.set(rotated.cols() - c - 1, r, at(r, c));
  return *this;
}

bool Block::inBounds(const Grid& grid, int r, int c) const {
  //TODO: Work out bounding logic, assuming tight bounds
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

FallingBlock::FallingBlock(const Block& block, int ticks) : Block(block) {
  setTicks(ticks);
  setPosition(0, 0);
}

void FallingBlock::getDisplayPosition(const Grid& grid, float& r, float& c) const {
  //TODO: Finish this logic
  r = this->r;
  c = this->c;
}

void FallingBlock::tick() {
  if (willFall()) {
    r++;
    currentTicks = 0;
  }
  else
    currentTicks++;
}

bool FallingBlock::landed(const Grid& grid) const {
  return collides(grid, r + 1, c);
}

void FallingBlock::plant(Grid& grid) const {
  for (int r1 = 0; r1 < rows(); r1++)
    for (int c1 = 0; c1 < cols(); c1++)
      if (at(r1, c1))
	grid.set(r - pr, c - pc, at(r1, c1));
}
