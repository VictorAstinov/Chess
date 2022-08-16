#include "Queen.h"
#include "Board.h"
#include "Square.h"

Queen::Queen(PieceInfo::Color color) : AbstractPiece{}, color{color} {}

std::vector<Square> Queen::doGetMoves(Square source, Board& board) {
    std::vector<Square> moves;
    return moves;
}

uint8_t Queen::doGetColor() {
    return color;
}

uint8_t Queen::doGetPiece() {
    return PieceInfo::Queen;
}