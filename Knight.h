#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include "AbstractPiece.h"

class Knight : public AbstractPiece {
  uint8_t color;
  uint8_t moved = false;

  std::vector<Square> doGetMoves(Square source, Board& board) override;
  uint8_t doGetColor() override;
  uint8_t doGetPiece() override;

  public:

  explicit Knight(PieceInfo::Color color);
};
#endif