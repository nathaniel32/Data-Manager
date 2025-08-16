# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c11

# Folder
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# File
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
BIN = $(BIN_DIR)/app

#######################################################################################################################
# gcc src/*.c -o bin/app
# Target default
all: $(BIN)

# executable
$(BIN): $(OBJ) | $(BIN_DIR)
	$(CC) $(OBJ) -o $@

# object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# create a folder if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)
#######################################################################################################################
# clean build
clean:
	rm -rf $(BUILD_DIR)/*.o $(BIN)

#######################################################################################################################
# run program
run: $(BIN)
	./$(BIN)