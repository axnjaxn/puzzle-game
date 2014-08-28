#ifndef _BPJ_PUZZLE_TETRIS_H
#define _BPJ_PUZZLE_TETRIS_H

#include "game.h"

class Tetris : public PuzzleGame {
protected:
  void postPlant();

public:
  Tetris();

  void left();
  void right();
  void fastDrop();
  void speedUp(bool on);
  void rotateLeft();
  void rotateRight();
  void hold();
  void pause();
  void update(int dt);
};

#endif
