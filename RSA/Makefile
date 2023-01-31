CC = g++
CFLAGS = -c -g -Wall -std=c++17 -fpermissive
EXENAME = M02

default:main.o RSA.o
	$(CC) main.o RSA.o -o $(EXENAME)

main.o:main.cpp RSA.h
	$(CC) $(CFLAGS) "$<"

clean:
	rm -r *.o $(EXENAME)

run:
	./$(EXENAME)