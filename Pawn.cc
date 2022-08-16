#include "Pawn.h"
#include "Square.h"
#include "Board.h"

Pawn::Pawn(PieceInfo::Color color) : AbstractPiece{}, color{color} {}

uint8_t Pawn::doGetColor() {
  return color;
}

uint8_t Pawn::doGetPiece() {
  return PieceInfo::Pawn;
}

std::vector<Square> Pawn::doGetMoves(Square source, Board& board) {
  std::vector<Square> moves;

  return moves; 
}