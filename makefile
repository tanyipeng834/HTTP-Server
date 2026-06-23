CC = gcc
CFLAGS = -Wall -Wextra -Werror -O -Iinclude
TARGET = server
SRC_DIR = src

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC_FILES:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET) 8080
