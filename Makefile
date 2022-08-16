CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -Werror=vla -MMD 
EXEC = Chess
OBJECTS = AbstractPiece.o AbstractPlayer.o Bishop.o Board.o Commands.o ComputerPlayer.o GameController.o GameState.o HumanPlayer.o King.o Knight.o main.o Pawn.o Queen.o Rook.o Square.o Subject.o TextObserver.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}