CC= gcc
STD= -std=c99 -pedantic
CFLAGS= -Wall -g
OBJS= main.o scopetest.o
OUTPUT= main.app

.PHONY: all
all: $(OBJS)
	$(CC) $(STD) $(CFLAGS) $(OBJS) -o $(OUTPUT)
clean:
	rm *.o $(OUTPUT)
