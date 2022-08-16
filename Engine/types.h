#ifndef TYPES_H_
#define TYPES_H_

enum Square : int {
  SQ_A1, SQ_B1, SQ_C1, SQ_D1, SQ_E1, SQ_F1, SQ_G1, SQ_H1,
  SQ_A2, SQ_B2, SQ_C2, SQ_D2, SQ_E2, SQ_F2, SQ_G2, SQ_H2,
  SQ_A3, SQ_B3, SQ_C3, SQ_D3, SQ_E3, SQ_F3, SQ_G3, SQ_H3,
  SQ_A4, SQ_B4, SQ_C4, SQ_D4, SQ_E4, SQ_F4, SQ_G4, SQ_H4,
  SQ_A5, SQ_B5, SQ_C5, SQ_D5, SQ_E5, SQ_F5, SQ_G5, SQ_H5,
  SQ_A6, SQ_B6, SQ_C6, SQ_D6, SQ_E6, SQ_F6, SQ_G6, SQ_H6,
  SQ_A7, SQ_B7, SQ_C7, SQ_D7, SQ_E7, SQ_F7, SQ_G7, SQ_H7,
  SQ_A8, SQ_B8, SQ_C8, SQ_D8, SQ_E8, SQ_F8, SQ_G8, SQ_H8,
  SQ_NONE,

  SQUARE_ZERO = 0,
  SQUARE_NUMBER = 64
};

enum MoveValue : int {
  VALUE_ZERO      = 0,
  VALUE_DRAW      = 0,
  VALUE_KNOWN_WIN = 10000,
  VALUE_MATE      = 32000,
  VALUE_INFINITE  = 32001,
  VALUE_NONE      = 32002,
};

enum CastlingRights : int {
  WHITE_SHORT, WHITE_LONG,
  BLACK_SHORT, BLACK_LONG,
  CASTLING_RIGHTS_NB
};

// TODO: give theses values
enum PieceValue : int {
  PawnValueMG, PawnValueEG,
  KnightValueMG, KnightValueEG,
  BishopValueMG, BishopValueEG,
  RookValueMG, RookValueEG,
  QueenValueMG, QueenValueEG
};

enum BasePieceTypes {
  ALL_PIECES,
  PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING,
  PIECE_TYPE_NUMBER = 8
};

enum EngineColor {
  WHITE,
  BLACK,
  COLOR_NUM
};

enum Piece {
  NO_PIECE,
  W_PAWN = PAWN, W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING,
  B_PAWN = PAWN + 8, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING,
  PIECE_NUMBER = 16
};

struct Move {
  Square src;
  Square dest;
};


#endif