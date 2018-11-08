.PHONY: all

all: swap

swap: main.o list.o
	g++ -o swap main.o list.o
main.o: main.cpp
	g++ -c main.cpp
list.o: l_impl.cpp
	g++ -c -o list.o l_impl.cpp
