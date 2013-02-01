CC= gcc
STD= -std=c99 -pedantic
CFLAGS= -Wall -g
OBJS= main.o
OUTPUT= main.app

all: $(OBJS)
	$(CC) $(STD) $(CFLAGS) $(OBJS) -o $(OUTPUT)
clean:
	rm *.o *.dat $(OUTPUT)
