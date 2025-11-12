# Static vs Dynamic Libraries Demo

This directory contains examples demonstrating the difference between **static** and **dynamic** library linking in C.

## 📁 Directory Structure

```
2 - Static vs Dynamic libraries/
├── 1 - Static libraries/      ← Simple static library example
├── 2 - Dynamic libraries/     ← Simple dynamic library example
├── mathlib.c/h               ← Comprehensive example files
├── stringlib.c/h
├── main_static.c
├── main_dynamic.c
└── Makefile                  ← Builds both types together
```

## 🎯 Quick Start

### Option 1: Simple Examples (Recommended for Learning)

**Static Library:**
```bash
cd "1 - Static libraries"
make run
make info
```

**Dynamic Library:**
```bash
cd "2 - Dynamic libraries"
make run
make info
make test-dependency  # See what happens without .so file
```

### Option 2: Comprehensive Comparison

Build and compare both types side-by-side:
```bash
make all          # Build everything
make run-both     # Run both programs
make compare      # Compare file sizes
make check-deps   # Check dependencies
```

## 📚 What You'll Learn

Each subdirectory contains a complete, simple example:

### 1 - Static libraries/
- How to create `.a` archive files
- Using the `ar` command
- Linking with static libraries
- Benefits and tradeoffs

### 2 - Dynamic libraries/
- How to create `.so` shared libraries
- Position Independent Code (`-fPIC`)
- Runtime library dependencies
- Testing without library present

---

# Detailed Documentation

## Files Overview

### Library Files
- **mathlib.h / mathlib.c** - Math utility functions (add, subtract, multiply, factorial)
- **stringlib.h / stringlib.c** - String utility functions (length, reverse, uppercase)

### Programs
- **main_static.c** - Program that uses static libraries
- **main_dynamic.c** - Program that uses dynamic libraries

### Build System
- **Makefile** - Comprehensive build system for creating both library types

## Static vs Dynamic Libraries

### Static Libraries (.a files)

**How they work:**
- Library code is copied into the executable at compile time
- Archive format (created with `ar` command)
- Linked using `-l` flag

**Advantages:**
- ✅ Faster execution (no runtime linking)
- ✅ Self-contained executable
- ✅ No external dependencies at runtime

**Disadvantages:**
- ❌ Larger executable size
- ❌ Must recompile to update library
- ❌ Memory waste when multiple programs use same library

**Creation:**
```bash
gcc -c mathlib.c -o mathlib.o        # Compile to object file
ar rcs libmath.a mathlib.o            # Create archive
gcc main.c -L. -lmath -o prog         # Link with library
```

### Dynamic Libraries (.so files)

**How they work:**
- Library code remains separate from executable
- Loaded into memory at runtime
- Shared between multiple programs

**Advantages:**
- ✅ Smaller executable size
- ✅ Can update library without recompiling program
- ✅ Shared in memory between programs
- ✅ Saves disk space

**Disadvantages:**
- ❌ Slight runtime overhead
- ❌ Must have library file at runtime
- ❌ Potential version conflicts

**Creation:**
```bash
gcc -fPIC -shared mathlib.c -o libmath.so          # Create shared library
gcc main.c -L. -lmath -Wl,-rpath,. -o prog         # Link with library
```

## Building and Running

### Build Everything
```bash
make all
```

### Build Static Version Only
```bash
make static
```

### Build Dynamic Version Only
```bash
make dynamic
```

### Run Programs
```bash
make run-static     # Run static version
make run-dynamic    # Run dynamic version
make run-both       # Run both versions
```

### Compare File Sizes
```bash
make compare
```
This shows the size difference between static and dynamic executables.

### Check Dynamic Dependencies
```bash
make check-deps
```
Shows which shared libraries the dynamic program depends on.

### Clean Build Artifacts
```bash
make clean
```

## Key Concepts Demonstrated

### 1. Position Independent Code (PIC)
- Required for shared libraries
- `-fPIC` flag allows code to be loaded at any memory address
- Not needed for static libraries

### 2. Library Naming Convention
- Static: `libname.a`
- Dynamic: `libname.so`
- Link with: `-lname` (without lib prefix and extension)

### 3. Library Search Path
- `-L.` tells linker to search current directory
- `-Wl,-rpath,.` sets runtime library search path
- Can also use `LD_LIBRARY_PATH` environment variable

### 4. Archive Tool (ar)
- `r` - Replace/insert files into archive
- `c` - Create archive if it doesn't exist
- `s` - Create index (symbol table)

## Typical Output Comparison

After building, you should see:
- **Static executable**: Larger (~20-30 KB)
- **Dynamic executable**: Smaller (~15-20 KB)
- **Static libraries (.a)**: ~2-3 KB each
- **Dynamic libraries (.so)**: ~8-10 KB each

## When to Use Each Type

### Use Static Libraries When:
- Building standalone applications
- Deployment simplicity is important
- Performance is critical
- You want to avoid dependency issues

### Use Dynamic Libraries When:
- Multiple programs use the same library
- You need to update libraries independently
- Disk space/memory is limited
- Building a plugin system

## Learning Exercises

1. **Modify a library function** and rebuild to see the difference between static and dynamic linking
2. **Run `ldd` on both executables** to see library dependencies
3. **Use `nm` command** to list symbols in libraries
4. **Try removing a .so file** and run the dynamic program to see what happens
5. **Use `size` command** to compare section sizes

## Common Commands

```bash
# List symbols in library
nm libmath.a
nm -D libmath.so

# Check library dependencies
ldd prog_dynamic

# See file sizes
ls -lh *.a *.so prog_*

# See executable sections
size prog_static prog_dynamic

# Search for symbol in library
nm libmath.so | grep add
```

## Notes

- The `-Wl,-rpath,.` flag embeds the current directory into the runtime library search path
- Without rpath, you'd need to set `LD_LIBRARY_PATH=. ./prog_dynamic`
- On macOS, use `.dylib` instead of `.so` for dynamic libraries
- On Windows, use `.lib` for static and `.dll` for dynamic libraries
