#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include <memory>
#include <cstdint>
#include "AbstractPiece.h"

class Board {
  std::vector<std::vector<std::unique_ptr<AbstractPiece>>> board;

  public:

  class BoardIterator {
    std::vector<std::vector<std::unique_ptr<AbstractPiece>>>& b;
    uint8_t position;
    BoardIterator(std::vector<std::vector<std::unique_ptr<AbstractPiece>>>& board, const uint8_t square);
    public:
    BoardIterator& operator++();
    std::unique_ptr<AbstractPiece>& operator*();
    bool operator!=(const BoardIterator& other);
    friend class Board;
  };

  BoardIterator begin();
  BoardIterator end();

  std::vector<std::unique_ptr<AbstractPiece>>& operator[](const uint8_t file);

  Board();
  ~Board() = default;
};
#endif
