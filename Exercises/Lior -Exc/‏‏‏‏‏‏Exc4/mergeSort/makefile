# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c17
LDFLAGS =

# Target executable
TARGET = mergeSort

# Source files
SRCS = main.c mergeSort.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = mergeSort.h

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compile source files to object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean

# Run the program
run: $(TARGET)
	./$(TARGET)
