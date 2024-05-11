SRCS = ./src/main.c
TARG = ./bin/run/mishell

CC = gcc

OPTS = -Wall
OTPS += -O


$(TARG): $(OBJS)
	$(CC) -c ./src/meshellcfg.c -o ./build/meshellcfg.o
	$(CC) -c ./src/main.c -o ./build/main.o
	$(CC) ./build/meshellcfg.o ./build/main.o -o ./bin/run/mishell

clean:
	rm -f ./build/* ./bin/run/mishell

