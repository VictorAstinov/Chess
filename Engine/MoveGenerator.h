#ifndef MOVE_GENERATOR_H_
#define MOVE_GENERATOR_H_
#include "types.h"
#include "Position.h"
#include <vector>


class MoveList {

  std::vector<Move> movelist;

  // helpers

  void generatePawnMoves(Position& pos);
  void generateKnightMoves(Position& pos);
  void generateBishopMoves(Position& pos);
  void generateQueenMoves(Position& pos);
  void generateKingMoves(Position& pos);
  
  public:
  
  static std::vector<Move>& generate_moves(Position& pos);
};
#endif