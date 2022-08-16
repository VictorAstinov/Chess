#include "ComputerPlayer.h"
#include "Square.h"
#include <utility>

ComputerPlayer::ComputerPlayer() : AbstractPlayer{} {}

int ComputerPlayer::doGetPlayerType() {
  return PlayerInfo::Computer;
}

// placeholder for now
std::pair<Square,Square> ComputerPlayer::doMove(Square src, Square dest) {
  // calculate src and dest then return them
  return {src, dest};
}