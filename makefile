SRCS = ./src/main.c
TARG = ./bin/run/mishell

CC = gcc

OPTS = -Wall
OTPS += -O


$(TARG): $(OBJS)
	$(CC) -c ./src/main.c -o ./build/main.o
	$(CC) ./build/main.o -o ./bin/run/mishell
	$(CC) -o $(TARG) ./build/main.o

clean:
	rm -f ./build/* ./bin/run/mishell

