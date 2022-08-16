#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_
#include <memory>
#include <vector>
#include <iostream>
#include "GameView.h"
#include "GameState.h"


class GameController {
  GameState* state;
  std::istream &in;
  std::vector<std::unique_ptr<GameView>> observers;
  void init_players();
  public:
  GameController(GameState* state, std::istream& in);
  ~GameController() = default;
  int run();
};
#endif
