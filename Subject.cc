#include "Subject.h"
#include "GameView.h"
#include <algorithm>

Subject::~Subject() {
  for (auto o : observers) {
    detach(o);
  }
}

void Subject::attach(GameView* obv) {
  observers.push_back(obv);
}

void Subject::detach(GameView* obv) {
  /*
  int back = observers.size();
  for (int i = 0; i < back;) {
    if (obv == observers[i]) {
      std::swap(observers[i], observers[back - 1]);
        --back;
      continue;
    }
    ++i;
  }
  observers.erase(observers.begin() + back, observers.end());
  */
  // observers.erase(std::remove(observers.begin(), observers.end(), obv), observers.end());
  for (auto it = observers.begin(); it != observers.end();) {
    if  (*it == obv) {
      it = observers.erase(it);
    }
    else  {
      ++it;
    }
  }
}

void Subject::notifyObservers(std::string cmd) {
  for (auto o : observers) {
    o->notify(cmd);
  }
}
