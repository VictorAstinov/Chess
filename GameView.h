#ifndef _GAME_VIEW_H_
#define _GAME_VIEW_H_
#include <string>

class GameState;

class GameView {
  public:
  virtual void notify(std::string cmd) = 0;
  virtual ~GameView() = default;
};
#endif
