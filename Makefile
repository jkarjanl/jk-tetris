CC	:= gcc
CFLAGS	:= -std=c99 -Wall -Wextra -Wpedantic -Werror -O2
LDFLAGS	:=

TARGET	:= jk-tetris
SRC	:= src/main.c
OBJ	:= $(SRC:.c=.o)

.PHONY:	all run clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)
