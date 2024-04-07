# Compiler
CC = gcc

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Compiler flags
CFLAGS = -I$(INCLUDE_DIR)

# Output executable
EXECUTABLE = $(BUILD_DIR)/Game

# Default target
all: $(EXECUTABLE)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $^ -o $@

# Clean build artifacts
clean:
	rm -f $(BUILD_DIR)/*.o $(EXECUTABLE)
