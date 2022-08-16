#ifndef _HUMAN_PLAYER_H_
#define _HUMAN_PLAYER_H_
#include "AbstractPlayer.h"


class HumanPlayer : public AbstractPlayer {

  std::pair<Square,Square> doMove(Square src, Square dest) override;
  int doGetPlayerType() override;

  public:
  
  HumanPlayer();
};
#endif