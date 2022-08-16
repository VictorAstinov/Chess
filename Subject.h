#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include  <string>

class GameView;

class Subject {
  std::vector<GameView*> observers;
  public:
  Subject() = default;
  virtual ~Subject();
  void attach(GameView* obv);
  void detach(GameView* obv);
  void notifyObservers(std::string cmd);
};
#endif
