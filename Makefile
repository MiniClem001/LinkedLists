CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
LDFLAGS = -Lbuild

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/obj/%.o, $(SRC))
LIB = $(basename $(notdir $(SRC)))
TARGET = build/lib$(LIB).a

EXAMPLE_SRC = $(wildcard examples/*.c)
EXAMPLE_OBJ = $(patsubst examples/%.c, build/obj/%.o, $(EXAMPLE_SRC))
EXAMPLE_TARGET = build/example

all: $(TARGET) example
	@echo "--== OK ==--"

example: $(EXAMPLE_TARGET)
	@echo "--== EXAMPLE ==--"
	@./$(EXAMPLE_TARGET)

$(TARGET): $(OBJ)
	@echo "--== TARGET ==--"
	ar rcs $@ $<

$(EXAMPLE_TARGET): $(EXAMPLE_OBJ) $(TARGET)
	@echo "--== EXAMPLE_TARGET ==--"
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS) -l$(LIB)

$(OBJ): $(SRC)
	@echo "--== OBJ ==--"
	mkdir -p build/obj
	$(CC) $(CFLAGS) -c $< -o $@

$(EXAMPLE_OBJ): $(EXAMPLE_SRC)
	@echo "--== EXAMPLE_OBJ ==--"
	mkdir -p build/obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "--== CLEAN ==--"
	@rm -rf ./build/

.PHONY: all example clean
