CC = gcc

CFLAGS = -Wall -Wextra

TARGET = taskline

SRC = src/main.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) && ./$(TARGET)
