# cs335 missileCommand Project
# to compile your project, type make and press enter

all: missileCommand

missileCommand:  missileCommand.cpp johnC.cpp danielT.cpp joseR.cpp joseG.cpp
	g++   missileCommand.cpp johnC.cpp danielT.cpp joseR.cpp joseG.cpp libggfonts.a -Wall -lX11 -lGL -lGLU -lm -omissileCommandMain

clean:
	rm -f missileCommand
	rm -f *.o

