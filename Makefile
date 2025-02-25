CC = clang
CFLAGS = -Wall -Wextra -Werror -Iinclude
LDFLAGS = -L.

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
LIB = $(basename $(notdir $(SRC)))
TARGET = lib$(LIB).a

EXAMPLE_SRC = $(wildcard examples/*.c)
EXAMPLE_OBJ = $(EXAMPLE_SRC:.c=.o)
EXAMPLE_TARGET = example_usage

all: $(TARGET) example

$(TARGET): $(OBJ)
	@echo "TARGET: Creating library $@ with $<"
	ar rcs $@ $<

$(OBJ): $(SRC)
	@echo "Compiling $< to $@"
	$(CC) $(CFLAGS) -c $< -o $@

example: $(EXAMPLE_TARGET) $(TARGET)
	@echo "EXAMPLE_TARGET :"
	./$(EXAMPLE_TARGET)

$(EXAMPLE_TARGET): $(EXAMPLE_OBJ)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS) -l$(LIB)

$(EXAMPLE_OBJ): $(EXAMPLE_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) $(EXAMPLE_TARGET) $(EXAMPLE_OBJ)

.PHONY: all clean example
