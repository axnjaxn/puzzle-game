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
  SDL_Rect drect = rect;
  SDL_FillRect(target, &drect, 0);

  int xsc = rect.w / game->getGrid().cols();
  int ysc = rect.h / game->getGrid().rows();

  for (int r = 0; r < game->getGrid().rows(); r++)
    for (int c = 0; c < game->getGrid().cols(); c++) {
      drect.w = xsc;
      drect.h = ysc;
      drect.x = c * xsc;
      drect.y = r * ysc;
      if (game->getGrid().at(r, c)) 
	SDL_FillRect(target, &drect, 0xFFFFFFFF);
    }

  if (!game->isWaiting()) {
    FallingBlock& block = game->getFallingBlock();
    float r0, c0;
    block.getDisplayPosition(game->getGrid(), r0, c0);
    for (int r = 0; r < game->getGrid().rows(); r++)
      for (int c = 0; c < game->getGrid().cols(); c++) {
	drect.w = xsc;
	drect.h = ysc;
	drect.x = (int)((c + c0) * xsc);
	drect.y = (int)((r + r0) * ysc);
	if (game->getGrid().at(r, c)) 
	  SDL_FillRect(target, &drect, 0xFFFFFFFF);
      }
  }
  
  //TODO: Better rendering
}
