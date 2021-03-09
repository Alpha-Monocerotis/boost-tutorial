
CC = g++ -std=c++11

all: newton.o monteCarlo.o
	g++ -shared -fPIC -o libcomputing.so newton.o monteCarlo.o
	
newton.o: newton.h newton.cpp
	$(CC) -c -fPIC newton.cpp

monteCarlo.o: monteCarlo.h monteCarlo.cpp
	$(CC) -c -fPIC monteCarlo.cpp

.PHONY: clean

clean:
	-rm newton.o monteCarlo.o libcomputing.so