#ifndef _BISHOP_H_
#define _BISHOP_H_
#include "AbstractPiece.h"

class Bishop : public AbstractPiece {
  uint8_t color;
  uint8_t moved = false;

  std::vector<Square> doGetMoves(Square source, Board& board) override;
  uint8_t doGetColor() override;
  uint8_t doGetPiece() override;

  public:

  explicit Bishop(PieceInfo::Color color);
};
#endif