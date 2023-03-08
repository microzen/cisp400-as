CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17 -fpermissive
EXENAME = ImageEditor

default:main.o ImageEditor.o lodepng.o picture.o
	$(CXX) main.o ImageEditor.o lodepng.o picture.o -o $(EXENAME)

main.o:main.cpp ImageEditor.h lodepng.h picture.h
	$(CXX) $(CXXFLAGS) "$<"

clean:
	rm -r *.o $(EXENAME)

run:
	./$(EXENAME)
