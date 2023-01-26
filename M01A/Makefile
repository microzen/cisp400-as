CC = g++
CFLAGS = -c -g -Wall -std=c++17 -fpermissive
EXENAME = M01

default:M01.o
	$(CC) M01.o -o $(EXENAME)

M01.o:M01.cpp
	$(CC) $(CFLAGS) "$<"

clean:
	rm -r *.o $(EXENAME)

run:
	./$(EXENAME)