# Just saving the Makefile in lab4 to use later — do not include in submission

# Sample Makefile to compile C programs

CC = gcc
CFLAGS = -Wall -g  # Replace -g with -O when not debugging

DEPS    = jlplayerlab6.c Makefile
OBJS    = jlplayerlab6.o

EXECS   = jlplayerlab6

all: $(EXECS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXECS): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXECS)
	./$(EXECS)

clean:
	/bin/rm -i *.o $(EXECS)