
CC = gcc
CFLAGS = -O -Wall
LIBS = -lpthread


TARGET = jlplayerHMW4CS332


SRC = jlplayerHMW4CS332.c


all: $(TARGET)


$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)


clean:
	rm -f $(TARGET) *.o
