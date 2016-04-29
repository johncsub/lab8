# cs335 missileCommand Project
# to compile your project, type make and press enter

all: missileCommand

missileCommand:  missileCommand.cpp johnBC.cpp danielT.cpp joseR.cpp joseG.cpp
	g++   missileCommand.cpp johnBC.cpp danielT.cpp joseR.cpp joseG.cpp -Wall -lX11 -lGL -lGLU -lm -omissileCommandMain

clean:
	rm -f missileCommand
	rm -f *.o

