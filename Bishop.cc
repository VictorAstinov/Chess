#include "Bishop.h"
#include "Board.h"
#include "Square.h"

Bishop::Bishop(PieceInfo::Color color) : AbstractPiece{}, color{color} {}

std::vector<Square> Bishop::doGetMoves(Square source, Board& board) {
    std::vector<Square> moves;
    return moves;
}

uint8_t Bishop::doGetColor() {
    return color;
}

uint8_t Bishop::doGetPiece() {
    return PieceInfo::Bishop;
}