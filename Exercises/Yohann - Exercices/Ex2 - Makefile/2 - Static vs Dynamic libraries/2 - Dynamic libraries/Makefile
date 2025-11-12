# Makefile for Dynamic Library Example
#
# What is a dynamic library?
# - Shared library file (.so extension on Linux)
# - Library code is LOADED at runtime (not copied into executable)
# - Created with -fPIC (Position Independent Code) flag
# - Smaller executable, but requires .so file to run

CC = gcc
CFLAGS = -Wall -Wextra

# Library name (must start with 'lib' and end with '.so')
LIBRARY = libcalculator.so
PROG = prog

all: $(PROG)

# Create dynamic/shared library with Position Independent Code
#same as: $(CC) $(CFLAGS) -fPIC -c calculator.c -o calculator.o
#		  $(CC) $(CFLAGS -shared calculator.o -o $(LIBRARY)

$(LIBRARY): calculator.c calculator.h
	$(CC) $(CFLAGS) -fPIC -shared calculator.c -o $(LIBRARY)
	
# Link main program with dynamic library
$(PROG): main.c $(LIBRARY)
	$(CC) $(CFLAGS) -o $(PROG) main.c -L. -lcalculator -Wl,-rpath,.

run: $(PROG)
	./$(PROG)

clean:
	rm -f $(LIBRARY) $(PROG)

.PHONY: all run info test-dependency clean help
