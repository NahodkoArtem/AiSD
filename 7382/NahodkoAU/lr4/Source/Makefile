.PHONY:all

all: recovery

recovery: main.o BinTree.o
	g++ -o recovery main.o BinTree.o
main.o: main.cpp
	g++ -c main.cpp
BinTree.o: BinTree.cpp
	g++ -c BinTree.cpp
