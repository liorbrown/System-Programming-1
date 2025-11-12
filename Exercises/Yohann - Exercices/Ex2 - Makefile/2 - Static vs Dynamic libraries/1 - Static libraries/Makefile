# Makefile for Static Library Example
#
# What is a static library?
# - Archive of compiled object files (.a extension)
# - Library code is COPIED into the final executable
# - Created using 'ar' (archive) command
# - Larger executable, but no runtime dependencies

CC = gcc
CFLAGS = -Wall -Wextra
AR = ar
ARFLAGS = rcu

# Library name (must start with 'lib' and end with '.a') !
LIBRARY = libcalculator.a
PROG = prog

all: $(PROG)

# Step 1: Compile source file to object file
calculator.o: calculator.c calculator.h
	$(CC) $(CFLAGS) -c calculator.c -o calculator.o

# Step 2: Create static library from object file
$(LIBRARY): calculator.o
	$(AR) $(ARFLAGS) $(LIBRARY) calculator.o

# Step 3: Link main program with static library
$(PROG): main.c $(LIBRARY)
	$(CC) $(CFLAGS) -o $(PROG) main.c -L. -lcalculator

run: $(PROG)
	./$(PROG)

clean:
	rm -f *.o $(LIBRARY) $(PROG)
	@echo "Cleaned all build files"

.PHONY: all run info clean help
