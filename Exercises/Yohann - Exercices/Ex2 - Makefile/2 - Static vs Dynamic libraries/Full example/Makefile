# Makefile demonstrating static and dynamic library creation and usage
#
# Targets:
#   all         - Build everything
#   static      - Build static libraries and program
#   dynamic     - Build dynamic libraries and program
#   clean       - Remove all build artifacts
#   run-static  - Run the static version
#   run-dynamic - Run the dynamic version
#   compare     - Compare file sizes

CC = gcc
CFLAGS = -Wall -Wextra -g
AR = ar
ARFLAGS = rcs

# Library source files
MATHLIB_SRC = mathlib.c
STRINGLIB_SRC = stringlib.c

# Object files
MATHLIB_OBJ = mathlib.o
STRINGLIB_OBJ = stringlib.o

# Static library names
STATIC_MATHLIB = libmath.a
STATIC_STRINGLIB = libstring.a

# Dynamic library names
DYNAMIC_MATHLIB = libmath.so
DYNAMIC_STRINGLIB = libstring.so

# Executables
STATIC_PROG = prog_static
DYNAMIC_PROG = prog_dynamic

# Default target
all: static dynamic

# ========== STATIC LIBRARY BUILD ==========

# Build static libraries and program
static: $(STATIC_PROG)

# Create static math library
$(STATIC_MATHLIB): $(MATHLIB_OBJ)
	@echo "Creating static library: $@"
	$(AR) $(ARFLAGS) $@ $^
	@echo "Static library created successfully"

# Create static string library
$(STATIC_STRINGLIB): $(STRINGLIB_OBJ)
	@echo "Creating static library: $@"
	$(AR) $(ARFLAGS) $@ $^
	@echo "Static library created successfully"

# Build static program
$(STATIC_PROG): main_static.c $(STATIC_MATHLIB) $(STATIC_STRINGLIB)
	@echo "Building static program: $@"
	$(CC) $(CFLAGS) -o $@ main_static.c -L. -lmath -lstring
	@echo "Static program built successfully"

# ========== DYNAMIC LIBRARY BUILD ==========

# Build dynamic libraries and program
dynamic: $(DYNAMIC_PROG)

# Create dynamic math library (Position Independent Code)
$(DYNAMIC_MATHLIB): $(MATHLIB_SRC)
	@echo "Creating dynamic library: $@"
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^
	@echo "Dynamic library created successfully"

# Create dynamic string library (Position Independent Code)
$(DYNAMIC_STRINGLIB): $(STRINGLIB_SRC)
	@echo "Creating dynamic library: $@"
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^
	@echo "Dynamic library created successfully"

# Build dynamic program
$(DYNAMIC_PROG): main_dynamic.c $(DYNAMIC_MATHLIB) $(DYNAMIC_STRINGLIB)
	@echo "Building dynamic program: $@"
	$(CC) $(CFLAGS) -o $@ main_dynamic.c -L. -lmath -lstring -Wl,-rpath,.
	@echo "Dynamic program built successfully"

# ========== OBJECT FILES ==========

# Compile object files for static libraries
$(MATHLIB_OBJ): $(MATHLIB_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(STRINGLIB_OBJ): $(STRINGLIB_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# ========== UTILITY TARGETS ==========

# Run static program
run-static: $(STATIC_PROG)
	@echo "\n========== Running Static Program =========="
	./$(STATIC_PROG)

# Run dynamic program
run-dynamic: $(DYNAMIC_PROG)
	@echo "\n========== Running Dynamic Program =========="
	./$(DYNAMIC_PROG)

# Run both and compare
run-both: run-static run-dynamic

# Compare file sizes
compare: $(STATIC_PROG) $(DYNAMIC_PROG)
	@echo "\n========== File Size Comparison =========="
	@echo "Static libraries:"
	@ls -lh $(STATIC_MATHLIB) $(STATIC_STRINGLIB) 2>/dev/null || echo "  (Not built yet)"
	@echo ""
	@echo "Dynamic libraries:"
	@ls -lh $(DYNAMIC_MATHLIB) $(DYNAMIC_STRINGLIB) 2>/dev/null || echo "  (Not built yet)"
	@echo ""
	@echo "Executables:"
	@ls -lh $(STATIC_PROG) $(DYNAMIC_PROG)
	@echo ""
	@echo "Notice: Static executable is larger (contains library code)"
	@echo "        Dynamic executable is smaller (links to .so files)"

# Show what libraries the dynamic program depends on
check-deps: $(DYNAMIC_PROG)
	@echo "\n========== Dynamic Program Dependencies =========="
	ldd $(DYNAMIC_PROG)

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -f *.o *.a *.so $(STATIC_PROG) $(DYNAMIC_PROG)
	@echo "Clean complete"

# Help target
help:
	@echo "Available targets:"
	@echo "  all         - Build both static and dynamic versions"
	@echo "  static      - Build static libraries and program"
	@echo "  dynamic     - Build dynamic libraries and program"
	@echo "  run-static  - Build and run static program"
	@echo "  run-dynamic - Build and run dynamic program"
	@echo "  run-both    - Run both programs"
	@echo "  compare     - Compare file sizes"
	@echo "  check-deps  - Show dynamic library dependencies"
	@echo "  clean       - Remove all build artifacts"
	@echo "  help        - Show this help message"

.PHONY: all static dynamic run-static run-dynamic run-both compare check-deps clean help
