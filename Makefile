CXX = g++-5
CXXFLAGS = -std=c++14 -Wall
EXEC = quadris
BJECTS = main.o cmdInterpreter.o Quadris.o LevelController.o Level.o Blocklib.o LevelZero.o LevelOne.o LevelTwo.o LevelThree.o LevelFour.o ViewController.o Score.o View.o TextDisplay.o GraphicsDisplay.o Grid.o Cell.o Subject.o BlockController.o Block.o HeavyBlock.o DirectedBlock.o HintEngine.o

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC}
