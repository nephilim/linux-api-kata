CC= gcc
STD= -std=c99 -pedantic
CFLAGS= -Wall -g
OBJS=main.o object.o
OUTPUT=main.app

.PHONY: all
all: $(OBJECTS)
	$(CC) $(STD) $(CFLAGS) $(OBJECTS) -o $(OUTPUT)
main.o: main.c
	$(CC) $(STD) $(CFLAGS) -c main.c
object.o: object.c
	$(CC) $(STD) $(CFLAGS) -c object.c
