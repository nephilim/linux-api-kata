CC= gcc
CFLAGS= -Wall -g -std=c99
OBJS= main.o
APP= main.app

.PHONY: all
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(APP)

.PHONY: clean 
clean:
	rm *.o $(APP)
