CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17 -fpermissive
EXENAME = M04

default:main.o Matrices.o
	$(CXX) main.o Matrices.o -o $(EXENAME)

main.o:main.cpp Matrices.h
	$(CXX) $(CXXFLAGS) "$<"

clean:
	rm -r *.o $(EXENAME)

run:
	./$(EXENAME)