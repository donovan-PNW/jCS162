all: final

final: list.o main.o supplied.o
	g++ -g -std=c++11 -no-pie list.o main.o supplied.o -o final

list.o: list.cpp
	g++ -g -std=c++11 list.cpp -c

main.o: main.cpp
	g++ -g -std=c++11 main.cpp -c

make clean:
	rm -rf list.o main.o final
