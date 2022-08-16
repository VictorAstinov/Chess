#include "Search.h"


RootMove::RootMove(Move m) : move{m} {}

bool RootMove::operator<(const RootMove& m) const {

  return m.value != value ? (value < m.value) : (prevValue < m.prevValue);

}



