#include "King.h"
#include "Board.h"
#include "Square.h"

King::King(PieceInfo::Color color) : AbstractPiece{}, color{color} {}

std::vector<Square> King::doGetMoves(Square source, Board& board) {
    std::vector<Square> moves;
    return moves;
}

uint8_t King::doGetColor() {
    return color;
}

uint8_t King::doGetPiece() {
    return PieceInfo::King;
}