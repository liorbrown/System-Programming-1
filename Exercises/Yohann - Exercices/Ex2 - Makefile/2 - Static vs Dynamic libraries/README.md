# Static vs Dynamic Libraries

This directory contains examples demonstrating the difference between **static** and **dynamic** library linking in C.

## 📚 Directory Structure

```
2 - Static vs Dynamic libraries/
├── 1 - Static libraries/      ← Simple static library example (START HERE!)
├── 2 - Dynamic libraries/     ← Simple dynamic library example
├── Full example/              ← Comprehensive comparison with multiple libraries
└── START_HERE.txt            ← Quick reference guide
```

## 🚀 Getting Started

### For Beginners - Simple Examples

Each subdirectory contains a self-contained, simple example:

#### **1 - Static libraries/**
```bash
cd "1 - Static libraries"
make run       # Build and run
make info      # See library details
```

Learn about:
- Creating `.a` archive files
- Using `ar` command
- Static linking
- Self-contained executables

#### **2 - Dynamic libraries/**
```bash
cd "2 - Dynamic libraries"
make run              # Build and run
make info             # See library details
make test-dependency  # See what happens without .so!
```

Learn about:
- Creating `.so` shared libraries
- Position Independent Code (`-fPIC`)
- Runtime dependencies
- Dynamic loading

### For Advanced Users - Full Example

```bash
cd "Full example"
make all          # Build both static and dynamic versions
make run-both     # Run both programs
make compare      # Compare file sizes
./demo.sh         # Full interactive demo
```

## 📊 Quick Comparison

| Feature | Static (.a) | Dynamic (.so) |
|---------|-------------|---------------|
| **Library location** | Inside executable | Separate file |
| **Executable size** | Larger | Smaller |
| **Runtime dependency** | None (self-contained) | Requires .so file |
| **Update library** | Must recompile | Just replace .so |
| **Loading speed** | Faster | Slight overhead |
| **Memory sharing** | No | Yes (multiple programs share) |

## 🎯 Learning Path

1. **Start with `1 - Static libraries/`**
   - Understand basic static linking
   - See how `ar` creates archives
   - Run the program and check it works without .a

2. **Move to `2 - Dynamic libraries/`**
   - Learn about shared libraries
   - Understand `-fPIC` flag
   - Test runtime dependency with `make test-dependency`

3. **Explore `Full example/`**
   - See both methods side-by-side
   - Compare file sizes
   - Understand real-world trade-offs

## 💡 Key Concepts

### Static Libraries
- Extension: `.a` (archive)
- Created with: `ar rcs libname.a object.o`
- Linked with: `gcc main.c -L. -lname`
- Result: Library code **copied into** executable

### Dynamic Libraries
- Extension: `.so` (shared object)
- Created with: `gcc -fPIC -shared -o libname.so source.c`
- Linked with: `gcc main.c -L. -lname -Wl,-rpath,.`
- Result: Library code **loaded at runtime**

## 🔧 Common Commands

```bash
# List symbols in library
nm libname.a           # Static
nm -D libname.so       # Dynamic

# Check program dependencies
ldd program            # Shows required .so files

# See library contents
ar -t libname.a        # List files in archive

# Compare sizes
ls -lh *.a *.so prog*
```

## ❓ When to Use Each?

### Use Static Libraries When:
- ✅ Building standalone applications
- ✅ Deployment simplicity is important
- ✅ Performance is critical
- ✅ Want to avoid version conflicts

### Use Dynamic Libraries When:
- ✅ Multiple programs use the same library
- ✅ Need to update libraries independently
- ✅ Disk space/memory is limited
- ✅ Building a plugin system

## 📖 Additional Resources

Each subdirectory contains its own detailed README with:
- Step-by-step build instructions
- Manual compilation commands
- Testing procedures
- Troubleshooting tips

**Happy Learning!** 🎉
