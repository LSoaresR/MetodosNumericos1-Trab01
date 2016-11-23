
CFLAGS += -Wall -Wextra

all: main.o

main.o:
	g++ src/main.cpp src/Dados.cpp src/NewtonRaphson.cpp -o make/main $(CFLAGS)

clean:
	rm make/*
