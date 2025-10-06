

CC = gcc
CFLAGS = -Wall -g  # Replace -g with -O when not debugging

DEPS    = searchHMW2jlplayer.c makefile
OBJS    = searchHMW2jlplayer.o

EXECS   = searchHMW2jlplayer

all: $(EXECS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXECS): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXECS)
	./$(EXECS) $(ARGS)

clean:
	/bin/rm -i *.o $(EXECS)






