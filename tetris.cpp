#include "tetris.h"

Tetris::Tetris() : PuzzleGame() {
  grid = Grid(20, 10);
  //TODO: More game parameters

  blocks.push_back(Block(2, 3).map(" =", "  ====", 1, 1));
  //TODO: More blocks

  fallingBlock = FallingBlock(blocks[0]);
  fallingBlock.setPosition(4, 4);
}

void Tetris::postPlant() {
  //TODO: Check for lines eliminated, etc.
}

//TODO: All controls
void Tetris::left() { }

void Tetris::right() { }

void Tetris::fastDrop() { }

void Tetris::speedUp(bool on) { }

void Tetris::rotateLeft() { }

void Tetris::rotateRight() { }

void Tetris::hold() { }

void Tetris::pause() { }

void Tetris::update(int dt) { }
