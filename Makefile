
LIB_DIR = lib/

CFLAGS += -Wall -Wextra -I $(LIB_DIR)

all: hello.o test.o

hello.o:
	g++ src/hello.cpp -o make/hello

test.o: lib/catch.h
	g++ test/hello_test.cpp -o make/test $(CFLAGS)

clean:
	rm make/*
