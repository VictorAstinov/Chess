#include "AbstractPlayer.h"
#include "Square.h"

std::pair<Square,Square> AbstractPlayer::move(Square src, Square dest) {
  return doMove(src, dest);
}

int AbstractPlayer::getPlayerType() {
  return doGetPlayerType();
}
