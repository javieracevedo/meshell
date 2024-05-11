SRCS = ./src/main.c
TARG = ./bin/run/mishell

CC = gcc

OPTS = -Wall
OTPS += -O


$(TARG): $(OBJS)
	$(CC) -c ./src/parser.c -o ./build/parser.o -g
	$(CC) -c ./src/utils.c -o ./build/utils.o -g
	$(CC) -c ./src/meshellcfg.c -o ./build/meshellcfg.o -g
	$(CC) -c ./src/main.c -o ./build/main.o -g
	$(CC) ./build/utils.o ./build/parser.o ./build/meshellcfg.o ./build/main.o -o ./bin/run/mishell -g

clean:
	rm -f ./build/* ./bin/run/mishell

