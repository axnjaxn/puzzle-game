#include "view.h"

PuzzleView::PuzzleView(PuzzleGame* game) {
  this->game = game;
  setTarget(NULL);
}

void PuzzleView::setTarget(SDL_Surface* target, SDL_Rect* rect) {
  if (target) {
    this->target = target;
    if (rect) this->rect = *rect;
    else {
      this->rect.x = this->rect.y = 0;
      this->rect.w = target->w;
      this->rect.h = target->h;
    }
  }
  else {
    target = NULL;
    this->rect.x = this->rect.y = this->rect.w = this->rect.h = 0;
  }
}

void PuzzleView::repaint() {
  //TODO
}
