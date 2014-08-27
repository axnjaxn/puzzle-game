#ifndef _BPJ_PUZZLE_TETRIS_H
#define _BPJ_PUZZLE_TETRIS_H

#include "game.h"

class Tetris : public PuzzleGame {
protected:
  Block selectBlock();
  void postPlant();

public:
  Tetris();
};

#endif
