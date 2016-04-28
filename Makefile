# cs335 lab1
# to compile your project, type make and press enter

all: missileCommand

missileCommand: missileCommand.cpp
	g++  missileCommand.cpp -Wall -lX11 -lGL -lGLU -lm -o missileCommand

clean:
	rm -f missileCommand
	rm -f *.o

