#include "Square.h"
#include <stdexcept>
#include <string>

Square::Square(int rank, int file) : rank{rank}, file{file} {}

std::istream& operator>>(std::istream& in, Square& square) {
  char file = 0;
  char rank = 0;

  in >> file >> rank;
  // convert to lower case if upper case -> allows for more input flexibility
  if (file < 'a') {
    file += ('a' - 'A');
  }
  // throw if the square is invalid
  if (file < 'a' || file > 'h' || rank < '1' || rank > '8') {
    throw std::invalid_argument{"Invalid square!"};
  }

  square.file = file - 'a';
  square.rank = rank - '1';
  
  return in;
}
