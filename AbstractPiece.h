#ifndef _ABSTRACT_PIECE_H_
#define _ABSTRACT_PIECE_H_
#include <cstdint>
#include <vector>

namespace PieceInfo {
  enum PieceType {Pawn, Knight, Bishop, Rook, Queen, King};
  enum Color {Black, White};
}

class Square;
class Board;

class AbstractPiece {
  virtual uint8_t doGetPiece() = 0;
  virtual uint8_t doGetColor() = 0;
  virtual std::vector<Square> doGetMoves(Square source, Board& board) = 0;

  public:

  std::vector<Square> get_moves(Square source, Board& board);
  uint8_t get_color();
  uint8_t get_piece();
  AbstractPiece() = default;
  virtual ~AbstractPiece() = default;
};
#endif
