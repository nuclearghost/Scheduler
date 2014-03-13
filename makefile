CC=clang++
CFLAGS=-std=c++11 -stdlib=libc++ -Weverything
SOURCES=main.cpp fifo.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLES=helo

all: tester

#main:
#	clang++ -std=c++11 -stdlib=libc++ -Weverything main.cpp -o hello

tester:
	$(CC) $(CFLAGS) fifo.cpp wpqs.cpp main.cpp -o tester

hello: main.o fifo.o
	$(CC) main.o fifo.o -o hello

main.o: main.cpp fifo.cpp
	$(CC) $(CFLAGS) fifo.o main.cpp

fifo.o: fifo.cpp
	$(CC) $(CFLAGS) fifo.cpp

clean:
	rm -rf *o *~ tester
