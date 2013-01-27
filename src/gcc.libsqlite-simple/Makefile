CC= gcc
STD= -std=c99 -pedantic
CFLAGS= -Wall

LIBS= -lsqlite3
OBJS= main.o
OUTPUT= main.app

all: $(OBJS)
	$(CC) $(STD) $(CFLAGS) $(OBJS) $(LIBS) -o $(OUTPUT)

.PHONY: all

clean:
	rm *.o $(OUTPUT)

.PHONY: clean 
