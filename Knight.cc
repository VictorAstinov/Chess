#include "Knight.h"
#include "Board.h"
#include "Square.h"

Knight::Knight(PieceInfo::Color color) : AbstractPiece{}, color{color} {}

std::vector<Square> Knight::doGetMoves(Square source, Board& board) {
    std::vector<Square> moves;
    return moves;
}

uint8_t Knight::doGetColor() {
    return color;
}

uint8_t Knight::doGetPiece() {
    return PieceInfo::Knight;
}