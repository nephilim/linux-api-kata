CC= gcc
STD= -std=c99 -pedantic
CFLAGS= -Wall -g
OBJS= main.o
OUTPUT= main.app

.PHONY: all main clean
all: main
	$(CC) $(STD) $(CFLAGS) $(OBJS) -o $(OUTPUT)
main: main.c
	$(CC) $(STD) $(CFLAGS) -c main.c
clean: 
	rm $(OUTPUT) *.o
