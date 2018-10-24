all: exec

exec: main.o supplied.o array.o
	g++ -no-pie main.o array.o supplied.o -o exec

main.o: main.cpp
	g++ -g -Wall -c main.cpp

array.o:
	g++ -g -Wall -c array.cpp

clean:
	rm exec array.o main.o





