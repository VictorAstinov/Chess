#ifndef _POSITION_H_
#define _POSITION_H_
#include <bitset>
#include <optional>
#include "types.h"

typedef std::bitset<SQUARE_NUMBER> BitBoard;

class Position {

  // data members TODO: add 3 move rep hashmap (using fen strings?)
  BitBoard board;
  BitBoard boardByColor[COLOR_NUM];
  BitBoard boardByPiece[PIECE_TYPE_NUMBER];
  EngineColor sideToMove;
  int fiftyMove = 0;
  Square enPassantSquare;
  std::bitset<CASTLING_RIGHTS_NB> castlingRights;
  
  // helpers
  void setKings(BitBoard& board);
  void setQueens(BitBoard& board);
  void setRooks(BitBoard& board);
  void setBishops(BitBoard& board);
  void setKnights(BitBoard& board);
  void setPawns(BitBoard& board);


  public:

  Position();

  // moving pieces
  Position& doMove(const Move m);

  // position properties
  EngineColor toMove() const;
  
};
#endif