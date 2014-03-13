CC=clang++
CFLAGS=-std=c++11 -stdlib=libc++ -Weverything
SOURCES=main.cpp fifo.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLES=helo

all: tester

#main:
#	clang++ -std=c++11 -stdlib=libc++ -Weverything main.cpp -o hello

tester:
	$(CC) $(CFLAGS) scheduler.cpp fifo.cpp wpqs.cpp main.cpp -o tester

clean:
	rm -rf *o *~ tester
