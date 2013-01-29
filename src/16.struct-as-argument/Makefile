CC= gcc
STD= -std=c99 -pedantic
CFLAGS= -Wall -g
OBJS= main.o
OUTPUT= main.app

all: $(OBJS)
	$(CC) $(STD) $(CFLAGS) $(OBJS) -o $(OUTPUT)
main.o: main.c
	$(CC) $(STD) $(CFLAGS) -c main.c
clean: 
	rm *.o $(OUTPUT)
