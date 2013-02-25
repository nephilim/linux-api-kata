CC= gcc
STDS= -std=c99 -pedantic
CFLAGS= -Wall -g
OBJS= main.o
OUTPUT= main.app

.PHONY: all
all: $(OBJS)
	$(CC) $(STDS) $(CFLAGS) $(OBJS) -o $(OUTPUT)

main.o: main.c 
	$(CC) $(STDS) $(CFLAGS) -c main.c

clean:
	rm *.o $(OUTPUT)
