CC =g++
CFLAGS = -std=c++17 -Wall -Werror -I$(GTEST_DIR)/include
LDFLAGS = -L$(GTEST_DIR)/lib -lgtest -lgtest_main -lpthread

GTEST_DIR = ../lib/googletest

all: test

test: test.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f test

.PHONY: all clean
