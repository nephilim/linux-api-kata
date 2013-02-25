CC= gcc
STD= -std=c99 -pedantic
CFLAGS= -Wall -g
OBJS= main.o
APP= main.app

all: $(OBJS)
	$(CC) $(STD) $(CFLAGS) $(OBJS) -o $(APP)
clean:
	rm $(OBJS) $(APP)
