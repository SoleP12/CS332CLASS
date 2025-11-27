# Compiler and flags
CC = gcc
CFLAGS = -O -Wall
LIBS = -lpthread

# Executable name
TARGET = jlplayerHMW4CS332

# Source file
SRC = jlplayerHMW4CS332.c

# Default rule
all: $(TARGET)

# Build executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

# Clean rule
clean:
	rm -f $(TARGET) *.o
