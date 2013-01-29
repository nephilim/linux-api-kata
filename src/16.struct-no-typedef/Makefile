CC= gcc
STD= -std=c99 -pedantic
CFLAGS= -Wall -g
OBJS= main.o person.o
OUTPUT= main.app

all: $(OBJS)
	$(CC) $(STD) $(CFLAGS) $(OBJS) -o $(OUTPUT)
main.o: main.c
	$(CC) $(STD) $(CFLAGS) -c main.c
person.o: person.c
	$(CC) $(STD) $(CFLAGS) -c person.c
clean: 
	rm *.o $(OUTPUT)
