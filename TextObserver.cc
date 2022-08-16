#include "TextObserver.h"
#include "GameState.h"
#include "Commands.h"
#include "Board.h"
#include "AbstractPiece.h"
#include <iostream>
#include <string>
using namespace std;

TextObserver::TextObserver(GameState *s) : subject{s} {
  subject->attach(this);
}

TextObserver::~TextObserver() {
  subject->detach(this);
}

void TextObserver::notify(string cmd) {
  if (cmd == cmds::init_players) {
    init_players();
  }
  else if (cmd == cmds::invalid) {
    invalid();
  }
  else if (cmd == cmds::print) {
    print_board();
  }
  else if (cmd == cmds::notify_move) {
    notifyMove();
  }
  else if (cmd == cmds::illegal_move) {
    illegalMove();
  }
}

void TextObserver::notifyMove() {
  string player = subject->isWhiteMove() ? "White" : "Black";
  cout << player << " to move: " << endl;
}

void TextObserver::invalid() {
  cout << "Invalid command!" << endl;
}

void TextObserver::illegalMove() {
  cout << "Not a legal move, try again!" << endl;
}

void TextObserver::init_players() {
  string player{"white"};
  if (subject->getTotalPlayers()) {
    player = string{"black"};
  }
  cout << "Is " << player << " a human (h) or computer (c)" << endl;
}

void TextObserver::print_board() {
  Board& board = subject->getBoard();
  char colors[] = {'B', 'W'};
  char pieces[] = {'P', 'N', 'B', 'R', 'Q', 'K'};
  if (!subject->isWhiteHuman()) {
    for (int file = 0; file < 8; ++file) {
      for (int rank = 7; rank >= 0; --rank) {
        if (board[rank][file].get()) {
          cout << colors[board[rank][file]->get_color()] << pieces[board[rank][file]->get_piece()] << "|";
        }
        else {
          cout << "   ";
        }
      }
      cout << endl;
    }
  }
  else {
    for (int file = 7; file >= 0; --file) {
      for (int rank = 0; rank < 8; ++rank) {
        if (board[rank][file].get()) {
          cout << colors[board[rank][file]->get_color()] << pieces[board[rank][file]->get_piece()] << "|";
       }
        else {
          cout << "   ";
        }
      }
      cout << endl;
    }
  }
}
