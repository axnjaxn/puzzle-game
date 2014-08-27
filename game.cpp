#include "game.h"

PuzzleGame::PuzzleGame() {
  queueSize = 1;
  waiting = dead = 0;
  clock = blockDelayTime = 0;
  blockTickTime = 1000;
  score = 0;
}

Block PuzzleGame::selectBlock() {
  //TODO
  return Block();
}

//TODO: Cleanup
void PuzzleGame::update(int dt) {
  clock += dt;
  if (dead) return;

  if (waiting) {
    if (clock >= blockDelayTime) {
      clock -= blockDelayTime;
      waiting = 0;
      //TODO: Start the next block, etc.
      update(0);
    }
    else return;
  }
  else {
    if (clock >= blockTickTime) {
      clock -= blockTickTime;
      if (fallingBlock.willFall()) {
	//TODO: Bunch of fall logic
      }
      else {
	fallingBlock.tick();
	update(0);
      }
    }
    else return;
  }
}
