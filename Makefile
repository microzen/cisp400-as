all: main clean run

CC = g++
override FLAGS += -g -Wall
override FLAGS += -std=c++17
override FLAGS += -fpermissive

SRCS = $(shell find ./M01A -type f -name '*.cpp')
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c "$<" -o "$@"

main: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o "$@"

clean:
	rm -f $(OBJS)

run:
	./main
