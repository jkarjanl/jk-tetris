CC	:= gcc
CFLAGS	:= -std=c99 -Wall -Wextra -Wpedantic -Werror -O2
CFLAGS  += $(shell pkg-config --cflags sdl2)

LDFLAGS := $(shell pkg-config --libs sdl2)

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
