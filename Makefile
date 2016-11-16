CC = gcc

OBJS = sdriver.o graph_functions.o

all: sdriver

debug: sdebug


sdebug: $(OBJS)
		$(CC) -g -O0 -o sdriver $(OBJS)

sdriver: $(OBJS)
		$(CC) -o sdriver $(OBJS)
.c.o:
		$(CC) $(CFLAGS) -g -Wall -c $<
			
clean:
		rm -f sdriver *.o core
