#ifndef _COMPUTER_PLAYER_H_
#define _COMPUTER_PLAYER_H_
#include "AbstractPlayer.h"

class ComputerPlayer : public AbstractPlayer {
  // pointer to engine will go here

  std::pair<Square,Square> doMove(Square src, Square dest) override;
  int doGetPlayerType() override;

  public:

  ComputerPlayer();
};
#endif
