

prefix = $(shell dirname $(abspath $(lastword $(MAKEFILE_LIST))))/$(ROOT)

ADDITINAL_INCLUDE_DIR = -I$(prefix)/computation
ADDITINAL_LIB = -L$(prefix)/computation -Wl,-rpath=$(prefix)computation -lcomputing

all:main.o
	g++ -std=c++11 -o main main.o $(ADDITINAL_LIB)


main.o: main.cpp subsystem
	g++ -std=c++11 -c -fPIC main.cpp

subsystem:
	make -C ./computation