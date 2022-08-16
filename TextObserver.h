#ifndef _TEXT_OBSERVER_H_
#define _TEXT_OBSERVER_H_
#include "GameView.h"

class GameState;

class TextObserver : public GameView {
  GameState* subject;

  void init_players();
  void invalid();
  void print_board();
  void notifyMove();
  void illegalMove();
  
  public:
  void notify(std::string cmd) override;
  explicit TextObserver(GameState *s);
  ~TextObserver();
};
#endif
