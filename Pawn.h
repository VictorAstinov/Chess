#ifndef _PAWN_H_
#define _PAWN_H_
#include "AbstractPiece.h"

class Pawn : public AbstractPiece {
  uint8_t color;
  bool moved = false;

  uint8_t doGetColor() override;
  uint8_t doGetPiece() override;
  std::vector<Square> doGetMoves(Square source, Board& board) override;

  public:

  explicit Pawn(PieceInfo::Color color);
};
#endif