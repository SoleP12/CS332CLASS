# Just saving the Makefile in lab4 to use later — do not include in submission

# Sample Makefile to compile C programs

CC = gcc
CFLAGS = -Wall -g  # Replace -g with -O when not debugging

DEPS    = jlplayerlab4.c Makefile
OBJS    = jlplayerlab4.o

EXECS   = jlplayerlab4

all: $(EXECS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXECS): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXECS)
	./$(EXECS) file1.txt file2.txt

clean:
	/bin/rm -i *.o $(EXECS)