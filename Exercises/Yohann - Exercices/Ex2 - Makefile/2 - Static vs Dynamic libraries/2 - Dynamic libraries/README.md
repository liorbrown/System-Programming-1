# Dynamic Library Example

## What is a Dynamic Library?

A **dynamic library** (`.so` file on Linux, `.dll` on Windows, `.dylib` on macOS) is a shared library loaded at runtime. The library code is **NOT copied into your executable** - instead, it's loaded when the program runs.

## Key Characteristics

✅ **Smaller executable size**
✅ **Library can be updated independently**
✅ **Multiple programs share one copy in memory**
✅ **Saves disk space**
❌ **Requires .so file at runtime**
❌ **Slight loading overhead**

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

# Show library information and dependencies
make info

# Test that .so is required at runtime
make test-dependency

# Clean build files
make clean
```

## Manual Build Steps

If you want to build manually without Make:

```bash
# Step 1: Create dynamic library with PIC
gcc -fPIC -shared -o libcalculator.so calculator.c

# Step 2: Compile and link main program
gcc main.c -L. -lcalculator -Wl,-rpath,. -o prog

# Step 3: Run (requires .so file!)
./prog
```

## Understanding the Commands

### `gcc -fPIC -shared -o libcalculator.so calculator.c`
- `-fPIC` = Position Independent Code (required for shared libraries)
- `-shared` = Create a shared library
- Allows code to be loaded at any memory address

### `gcc main.c -L. -lcalculator -Wl,-rpath,. -o prog`
- `-L.` = Look for libraries in current directory
- `-lcalculator` = Link with libcalculator.so
- `-Wl,-rpath,.` = Embed runtime library search path (current dir)

## Testing

After building, try:
```bash
# See symbols in shared library
nm -D libcalculator.so

# Check program dependencies
ldd prog  # Shows libcalculator.so is needed

# Try removing the library
mv libcalculator.so libcalculator.so.backup
./prog  # Will fail!
mv libcalculator.so.backup libcalculator.so
```

## Key Concept

The executable `prog` does NOT contain the calculator code. If you delete `libcalculator.so`, the program will fail to run with an error like:
```
error while loading shared libraries: libcalculator.so: cannot open shared object file
```

## Alternative: Using LD_LIBRARY_PATH

If you don't use `-Wl,-rpath,.`, you can set the library path at runtime:
```bash
LD_LIBRARY_PATH=. ./prog
```
