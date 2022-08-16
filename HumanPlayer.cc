#include "HumanPlayer.h"
#include "Square.h"
#include <utility>

HumanPlayer::HumanPlayer() : AbstractPlayer{} {}

int HumanPlayer::doGetPlayerType() {
  return PlayerInfo::Human;
}

std::pair<Square, Square> HumanPlayer::doMove(Square src, Square dest) {
  // can add extra features here if needed
  return {src, dest};
}


