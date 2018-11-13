all:midterm

midterm: array.o main.o supplied.o
	g++ array.o main.o supplied.o -o midterm

array.o: array.cpp
	g++ -g array.cpp -c

main.o: main.cpp
	g++ -g main.cpp -c

make clean:
	rm -f array.o main.o midterm
