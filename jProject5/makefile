all: proj5

proj5: carEntry.o carEntryList.o main.o tools.o
	g++ -std=c++11 -g carEntry.o carEntryList.o main.o tools.o -o proj5

carEntry.o: carEntry.cpp
	g++ -std=c++11 -g -c carEntry.cpp

carEntryList.p: carEntryList.cpp
	g++ -std=c++11 -g -c carEntryList.cpp

main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp

tools.o: tools.cpp
	g++ -std=c++11 -g -c tools.cpp

make clean:
	rm -f proj5 *.o 
