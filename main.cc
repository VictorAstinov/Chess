#include "GameState.h"
#include "GameController.h"
#include <iostream>
#include <thread>

int main() {
  // do command line parsing here if cmd args get added
  std::cout << std::thread::hardware_concurrency() << std::endl;
  GameState state{};
  GameController controller{&state, std::cin};
  return controller.run();
}
