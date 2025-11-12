# Static Library Example

## What is a Static Library?

A **static library** (`.a` file on Linux) is an archive of compiled object files. When you link your program with a static library, the library code is **copied directly into your executable**.

## Key Characteristics

✅ **Library code is embedded in executable**
✅ **No external files needed at runtime**
✅ **Faster execution (no dynamic loading)**
❌ **Larger executable size**
❌ **Must recompile to update library**

## Files

- `calculator.h` - Header file with function declarations
- `calculator.c` - Implementation of calculator functions
- `main.c` - Main program using the library
- `Makefile` - Build system

## How to Build and Run

```bash
# Build everything
make

# Run the program
make run

# Show library information
make info

# Clean build files
make clean
```

## Manual Build Steps

If you want to build manually without Make:

```bash
# Step 1: Compile to object file
gcc -c calculator.c -o calculator.o

# Step 2: Create static library archive
ar rcs libcalculator.a calculator.o

# Step 3: Compile and link main program
gcc main.c -L. -lcalculator -o prog

# Step 4: Run
./prog
```

## Understanding the Commands

### `ar rcs libcalculator.a calculator.o`
- `ar` = Archive tool
- `r` = Replace/insert files
- `c` = Create archive if doesn't exist
- `s` = Create symbol index

### `gcc main.c -L. -lcalculator -o prog`
- `-L.` = Look for libraries in current directory
- `-lcalculator` = Link with libcalculator.a (removes 'lib' prefix and '.a' suffix)

## Testing

After building, try:
```bash
# Check library contents
ar -t libcalculator.a

# See symbols
nm libcalculator.a

# Check if executable is self-contained
ldd prog  # Should show only system libraries
```

## Key Concept

The executable `prog` contains all the calculator code. You can delete `libcalculator.a` and the program will still run!
