all: exec

exec: carEntry.o carEntryList.o main.o tools.o
	g++ -g carEntry.o carEntryList.o main.o tools.o -o exec

carEntry.o: carEntry.cpp
	g++ -g -c carEntry.cpp

carEntryList.p: carEntryList.cpp
	g++ -g -c carEntryList.cpp

main.o: main.cpp
	g++ -g -c main.cpp

tools.o: tools.cpp
	g++ -g -c tools.cpp

make clean:
	rm -f carEntry.o carEntryList.o main.o tools.o
