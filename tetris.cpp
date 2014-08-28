#include "tetris.h"

Tetris::Tetris() : PuzzleGame() {
  grid = Grid(20, 10);
  //TODO: More game parameters
}

void Tetris::postPlant() {
  //TODO
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
