all: video

video: video.o tools.o driver.o
	g++ video.o tools.o driver.o -o video

video.o: video.cpp
	g++ -c video.cpp

driver.o: driver.cpp
	g++ -c driver.cpp

tools.o: tools.cpp
	g++ -c tools.cpp

clean:
	rm *.o video	
