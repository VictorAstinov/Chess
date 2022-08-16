#include "AbstractPiece.h"
#include "Square.h"


std::vector<Square> AbstractPiece::get_moves(Square source, Board& board) {
  return doGetMoves(source, board);
}

uint8_t AbstractPiece::get_piece() {
  return doGetPiece();
}

uint8_t AbstractPiece::get_color() {
  return doGetColor();
}
