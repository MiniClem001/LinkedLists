CC = clang
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L.

SRC = src/liste_chainee.c
OBJ = $(SRC:.c=.o)
TARGET = libliste_chainee.a

all: $(TARGET)

$(TARGET): $(OBJ)
	@echo "Creating library $@ with $^"
	ar rcs $@ $^

$(OBJ): $(SRC)
	@echo "Compiling $< to $@"
	$(CC) $(CFLAGS) -c $< -o $@

examples: examples/examples.c $(TARGET)
	$(CC) $(CFLAGS) -o $@.out $< $(LDFLAGS) -lliste_chainee

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
