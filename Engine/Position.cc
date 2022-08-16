#include "Position.h"

void Position::setPawns(BitBoard& board) {
  for (int i = 0; i < 8; ++i) {
    board[i + SQ_A1] = true;
    board[i + SQ_A7] = true;
  }
}

void Position::setKnights(BitBoard& board) {
  board[SQ_B1] = true;
  board[SQ_G1] = true;
  board[SQ_B8] = true;
  board[SQ_G8] = true;
}

void Position::setBishops(BitBoard& board) {
  board[SQ_C1] = true;
  board[SQ_F1] = true;
  board[SQ_C8] = true;
  board[SQ_F8] = true;
}

void Position::setRooks(BitBoard& board) {
  board[SQ_A1] = true;
  board[SQ_H1] = true;
  board[SQ_A8] = true;
  board[SQ_H8] = true;
}

void Position::setQueens(BitBoard& board) {
  board[SQ_D1] = true;
  board[SQ_D8] = true;
}

void Position::setKings(BitBoard& board) {
  board[SQ_E1] = true;
  board[SQ_E8] = true;  
}

// default ctor makes a default chess board at the start of a game
Position::Position() {

  // white pieces
  for (int i = SQ_A1, j = SQ_A7; i <= SQ_H2; ++i, ++j) {
    // white pieces
    board[i] = true;
    boardByColor[WHITE][i] = true;
    // black pieces
    board[j] = true;
    boardByColor[BLACK][j] = true;
  }

  // set piece specific BBs
  setPawns(boardByPiece[PAWN]);
  setKnights(boardByPiece[KNIGHT]);
  setBishops(boardByPiece[BISHOP]);
  setRooks(boardByPiece[ROOK]);
  setQueens(boardByPiece[QUEEN]);
  setKings(boardByPiece[KING]);  
  
  enPassantSquare = SQ_NONE;
  sideToMove = WHITE;
  castlingRights.set();
  
}




