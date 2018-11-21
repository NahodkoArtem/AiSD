.PHONY: all

all: swap

swap: main.o Queue.o
	g++ -o swap main.o Queue.o
main.o: main.cpp Queue.h
	g++ -c main.cpp Queue.h
Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp Queue.h
