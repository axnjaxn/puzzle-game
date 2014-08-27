#ifndef _BPJ_PUZZLE_GAME_H
#define _BPJ_PUZZLE_GAME_H

#include "blocks.h"
#include <vector>
#include <queue>

/*
 * PuzzleGame class
 * Represents the game logic (i.e. model) of the game
 */
class PuzzleGame {
protected:
  std::vector<Block> blocks;
  std::queue<Block> blockQueue;
  int queueSize;

  Grid grid;
  FallingBlock fallingBlock;

  bool waiting, dead;
  int clock, blockTickTime, blockDelayTime;

  unsigned long int score;

  virtual Block selectBlock();
  virtual void postFall() { }
  virtual void postPlant() { }

public:
  PuzzleGame();
  
  inline void setBlocks(const std::vector<Block>& blocks) {this->blocks = blocks;}
  inline void setBlockTickTime(int time) {blockTickTime = time;}
  inline void setBlockDelayTime(int time) {blockDelayTime = time;}

  inline const Grid& getGrid() const {return grid;}
  inline FallingBlock& getFallingBlock() {return fallingBlock;}
  inline const FallingBlock& getFallingBlock() const {return fallingBlock;}
  inline const std::queue<Block>& getQueue() const {return blockQueue;}
  inline unsigned long int getScore() const {return score;}
  inline bool isWaiting() const {return waiting;}
  inline bool isDead() const {return dead;}

  virtual void update(int dt);
};

#endif
