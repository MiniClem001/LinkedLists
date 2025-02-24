CC = clang
CFLAGS = -Wall -Wextra -Werror -Iinclude
LDFLAGS = -L.

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = libliste_chainee.a

all: $(TARGET) examples

$(TARGET): $(OBJ)
# $(CC) $(CFLAGS) $(INCLUDE) -c $(SRC) -o $(OBJ)
	ar rcs $@ $^

examples: examples/examples.c $(TARGET)
	$(CC) $(CFLAGS) -o $@.out $< $(LDFLAGS) -lliste_chainee

clean:
	rm -f $(OBJ) $(TARGET) example

.PHONY: all clean
