all: practice

practice: supplied.o list.o main.o
	g++ -g -no-pie supplied.o list.o main.o -o practice

list.o: list.cpp
	g++ -g -c list.cpp

main.o: main.cpp
	g++ -g -c main.cpp

make clean:
	rm -rf practice list.o main.o
