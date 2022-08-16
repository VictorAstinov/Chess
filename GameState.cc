#include "GameState.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Commands.h"
#include <stdexcept>
#include "Square.h"
#include <utility>

using namespace std;

void GameState::init_players(char player) {
  if (player == 'h') {
    if (!players.size()) {
      whiteHuman = true;
    }
    players.emplace(players.begin(), std::make_unique<HumanPlayer>());
  }

  else if (player == 'c') {
    players.emplace(players.begin(), std::make_unique<ComputerPlayer>());
  }
  
  else {
    throw invalid_argument{"Invaid_player_type"};
  }
}

int GameState::getTotalPlayers() {
  return players.size();
}

bool GameState::isWhiteHuman() {
  return whiteHuman;
}

Board& GameState::getBoard() {
  return board;
}

bool GameState::isWhiteMove() {
  return whiteMove;
}

// TODO: add impl
// threat map for both sides
bool GameState::isValidMove(Square source, Square dest) {
  return true;
}

bool GameState::isCurrentPlayerHuman() {
  return players[whiteMove]->getPlayerType() == PlayerInfo::Human;
}

void GameState::move(Square source, Square dest) {
  // get and verify move made
  pair<Square, Square> move = players[whiteMove]->move(source, dest);
  if (!isValidMove(move.first, move.second)) {

    throw invalid_argument{cmds::illegal_move};

  }
  else {

    board[move.second.file][move.second.rank] = std::move(board[move.first.file][move.first.rank]);
    whiteMove = !whiteMove;

  }
}
