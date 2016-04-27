# cs335 lab1
# to compile your project, type make and press enter

all: lab1 dturack

lab1: lab1.cpp
	g++ lab1.cpp -Wall -olab1 -lX11 -lGL -lGLU -lm
	
dturack: dturack.cpp
	g++ dturack.cpp -Wall -odturack -lx11 -lGL -lGLU -lm

clean:
	rm -f lab1
	rm -f dturack
	rm -f *.o

