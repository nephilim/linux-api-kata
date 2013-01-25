CC=gcc
CFLAGS=-Wall -g -lsqlite3
OBJS=main.o
OUTPUT=main.app

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUTPUT)

clean:
	rm *.o $(OUTPUT)

