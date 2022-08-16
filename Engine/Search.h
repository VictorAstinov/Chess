#ifndef SEARCH_H_
#define SEARCH_H_
#include "types.h"

// Move + a score associated with it, will be the base of the search in a thread
struct RootMove {

  Move move;
  int value = -VALUE_INFINITE;
  int prevValue = -VALUE_INFINITE;

  explicit RootMove(Move m);
  ~RootMove() = default;

  bool operator<(const RootMove& m) const;
};


#endif