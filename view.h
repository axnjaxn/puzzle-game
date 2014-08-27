#ifndef _BPJ_PUZZLE_VIEW_H
#define _BPJ_PUZZLE_VIEW_H

#include "game.h"
#include <SDL/SDL.h>

class PuzzleView {
private:
  PuzzleGame* game;
  SDL_Surface* target;
  SDL_Rect rect;

public:
  PuzzleView(PuzzleGame* game = NULL);

  void setTarget(SDL_Surface* target, SDL_Rect* rect = NULL);
  void repaint();
};

#endif
