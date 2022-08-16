#ifndef _ABSTRACT_PLAYER_H_
#define _ABSTRACT_PLAYER_H_
#include <utility>
#include "Square.h"

namespace PlayerInfo{
  enum PlayerType{Human, Computer};
}

class AbstractPlayer {
  virtual std::pair<Square,Square> doMove(Square src, Square dest) = 0;
  virtual int doGetPlayerType() = 0;

  public:

  int getPlayerType();
  std::pair<Square,Square> move(Square src, Square dest);
  virtual ~AbstractPlayer() = default;
};
#endif
