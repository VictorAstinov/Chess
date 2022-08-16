#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <memory>
#include <cstdint>
#include <iostream>

// thin wrapper around what is a square, no need for private fields
struct Square {
  uint8_t rank;
  uint8_t file;
  explicit Square(int rank = 0, int file = 0);
  ~Square() = default;
};
#endif

std::istream& operator>>(std::istream& in, Square& square);