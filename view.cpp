#include "view.h"

PuzzleView::PuzzleView(PuzzleGame* game) {
  this->game = game;
  setTarget(NULL);
}

void PuzzleView::setTarget(SDL_Surface* target, SDL_Rect* rect) {
  if (target) {
    this->target = target;
    if (rect) this->rect = rect;
    else {
      rect.x = rect.y = 0;
      rect.w = target->w;
      rect.h = target->h;
    }
  }
  else {
    target = NULL;
    rect.x = rect.y = rect.w = rect.h = 0;
  }
}

void PuzzleView::repaint() {
  //TODO
}
