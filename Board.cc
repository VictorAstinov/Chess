#include "Board.h"
#include "AbstractPiece.h"
#include "Rook.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Bishop.h"
#include <utility>
#include <stdexcept>

Board::Board() {
  
  board.resize(8); // number of files
  for (auto& rank : board) {
    rank.resize(8);
  }
  
  for (int rank = 0; rank < 8; ++rank) {
    for (int file = 0; file < 8; ++file) {
      
      std::unique_ptr<AbstractPiece> piece{nullptr};

      if (rank == 1 || rank == 6) {
        PieceInfo::Color color = (rank == 1) ? PieceInfo::White : PieceInfo::Black;
        piece = std::make_unique<Pawn>(color);
      }
        
      else if (rank == 0 || rank == 7) {
        
        PieceInfo::Color color = (rank == 0) ? PieceInfo::White : PieceInfo::Black;
        if (file == 0 || file == 7) {
          piece = std::make_unique<Rook>(color);
        }
        else if (file == 1 || file == 6) {
          piece = std::make_unique<Knight>(color);
        }
        else if (file == 2 || file == 5) {
          piece = std::make_unique<Bishop>(color);
        }
        else if (file == 3) {
          piece = std::make_unique<Queen>(color);
        }
        else {
          piece = std::make_unique<King>(color);
        }
        
      }
      
      board[file][rank] = std::move(piece);
      
    }
  }
}

Board::BoardIterator::BoardIterator(std::vector<std::vector<std::unique_ptr<AbstractPiece>>>& board, const uint8_t square) : b{board}, position{square} {}

Board::BoardIterator& Board::BoardIterator::operator++() {
  ++position;
  return *this;
}

std::unique_ptr<AbstractPiece>& Board::BoardIterator::operator*() {
  return b[position / 8][position % 8];
}

bool Board::BoardIterator::operator!=(const Board::BoardIterator& other) {
  return position != other.position;
}

Board::BoardIterator Board::begin() {
  return BoardIterator{this->board, 0};
}

Board::BoardIterator Board::end() {
  return BoardIterator{this->board, 64};
}

std::vector<std::unique_ptr<AbstractPiece>>& Board::operator[](const uint8_t file) {
  if (file < 0 || file > 7) {
    throw std::invalid_argument{"Out_of_bounds"};
  }
  return board[file];
}
