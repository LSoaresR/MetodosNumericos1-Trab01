
LIB_DIR  = lib/
SRC_DIR  = src/
TEST_DIR = test/

CFLAGS += -Wall -Wextra -I $(SRC_DIR) -I $(LIB_DIR) -I $(TEST_DIR)

all: newthon-raphson.o test.o

newthon-raphson.o:
	g++ src/main.cpp src/newthon-raphson.cpp src/Dados.cpp -o make/newthon-raphson

test.o:
	g++ test/main_test.cpp -o make/test $(CFLAGS)

clean:
	rm make/*
