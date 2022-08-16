#include "Rook.h"
#include "Square.h"
#include "Board.h"

Rook::Rook(PieceInfo::Color color) : AbstractPiece{}, color{color} {}

uint8_t Rook::doGetColor() {
  return color;
}

uint8_t Rook::doGetPiece() {
  return PieceInfo::Rook;
}

std::vector<Square> Rook::doGetMoves(Square source, Board& board) {
  std::vector<Square> moves;
  return moves; 
}
