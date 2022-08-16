#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_
#include "Subject.h"
#include "Board.h"
#include "AbstractPlayer.h"
#include <vector>
#include <memory>

class GameState : public Subject {
  Board board;
  std::vector<std::unique_ptr<AbstractPlayer>> players;
  bool whiteHuman = false;
  bool whiteMove = true;

  bool isValidMove(Square source, Square dest);

  public:

  void init_players(char player);
  bool isWhiteHuman();
  bool isWhiteMove();
  bool isCurrentPlayerHuman();
  int getTotalPlayers();
  Board& getBoard();
  void move(Square source, Square dest);
  GameState() = default;
  ~GameState() = default;
};
#endif
