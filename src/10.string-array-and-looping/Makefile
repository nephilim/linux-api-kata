CC=gcc
CFLAGS=-Wall -g
OBJS=main.o args_check.o
OUTPUT=app

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUTPUT)

clean:
	rm *.o $(OUTPUT)
