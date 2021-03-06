CXX = g++-5
CXXFLAGS = -std=c++14 -Wall
EXEC = quadris
OBJECTS = cmdInterpreter.o Quadris.o ViewController.o Score.o View.o TextDisplay.o GraphicsDisplay.o Grid.o Cell.o Subject.o BlockController.o Block.o HeavyBlock.o DirectedBlock.o HintEngine.o main.o LevelController.o Level.o LevelZero.o LevelOne.o LevelTwo.o LevelThree.o LevelFour.o BlockLib.o Info.o

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC}
