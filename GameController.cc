#include "GameController.h"
#include "GameState.h"
#include "TextObserver.h"
#include "Square.h"
#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include "Commands.h"
using namespace std;

GameController::GameController(GameState* state, istream& in) : state{state}, in{in} {}

void GameController::init_players() {
  for (int i = 0; i < 2; ++i) {
    while (true) {
      state->notifyObservers(cmds::init_players);
      char player;
      in >> player;
      // in case of failure to initilize
      if (in.eof() || in.fail()) {
        exit(cmds::ERROR);
      }
      try {
        state->init_players(player);
        break;
      }
      catch (invalid_argument& e) {
        state->notifyObservers(cmds::invalid);
      }
    }
  }
}

int GameController::run() {
  // add all observers and init players
  observers.emplace_back(make_unique<TextObserver>(state));
  init_players();
  // print iniital position and play game
  state->notifyObservers(cmds::print);

  while(true) {
    // notify whose move it is
    state->notifyObservers(cmds::notify_move);
    Square source{0,0};
    Square dest{0,0};

    // get input if human player
    if (state->isCurrentPlayerHuman()) {

      while (true) {
        string input{""};
        in >> input;

        if (input == "move") {

          try {
            in >> source >> dest;
            state->move(source, dest);
            break;
          }

          catch (invalid_argument &e) {
            state->notifyObservers(cmds::illegal_move);
          }

        }
        else {

          state->notifyObservers(cmds::invalid);

        }
      }
    }
    // computer will make a move
    else {
      state->move(source, dest);
    }
    // print board after a move
    state->notifyObservers(cmds::print);
  }

  return 0;
}
