#include "tetris.h"
#include "view.h"

#define TITLE "Puzzle Game Test by Brian Jackson"

int main(int argc, char* argv[]) {
  //Initialize SDL and catch init errors
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Fatal error initializing SDL");
    return 1;
  }
  atexit(SDL_Quit);
  
  Tetris game;

  SDL_WM_SetCaption(TITLE, NULL);
  SDL_Surface* screen = SDL_SetVideoMode(game.getGrid().cols() * 16, game.getGrid().rows() * 16,
					 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
  
  PuzzleView view(&game);
  view.setTarget(screen);

  SDL_Event event;
  bool exitflag = 0;
  while (!exitflag) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) exitflag = 1;
      else if (event.type == SDL_KEYDOWN) {
	switch (event.key.keysym.sym) {
	default: break;
	case SDLK_ESCAPE: exitflag = 1; break;
	}
      }
    }

    SDL_Delay(5);    
  }

  return 0;
}

