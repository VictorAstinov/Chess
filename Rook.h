#ifndef _ROOK_H_
#define _ROOK_H_
#include "AbstractPiece.h"

class Rook : public AbstractPiece {
  uint8_t color;
  bool moved = false;

  std::vector<Square> doGetMoves(Square source, Board& board) override;
  uint8_t doGetPiece() override;
  uint8_t doGetColor() override;

  public:

  explicit Rook(PieceInfo::Color color);

};
#endif
