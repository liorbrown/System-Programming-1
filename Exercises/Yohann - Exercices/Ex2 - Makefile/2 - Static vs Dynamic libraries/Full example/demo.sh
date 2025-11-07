#!/bin/bash

# Demo script to showcase static vs dynamic libraries

echo "=================================================="
echo "  Static vs Dynamic Libraries Demonstration"
echo "=================================================="
echo ""

# Build everything
echo "1. Building all libraries and programs..."
echo "--------------------------------------------------"
make clean > /dev/null 2>&1
make all
echo ""

# Show file sizes
echo "2. Comparing file sizes..."
echo "--------------------------------------------------"
make compare
echo ""

# Run both programs
echo "3. Running both programs..."
echo "--------------------------------------------------"
make run-both
echo ""

# Check dependencies
echo "4. Checking dynamic library dependencies..."
echo "--------------------------------------------------"
make check-deps
echo ""

# Additional analysis
echo "5. Additional Analysis..."
echo "--------------------------------------------------"

echo "Symbols in static library:"
nm libmath.a | grep -E "add|subtract|multiply|factorial" | head -4
echo ""

echo "Symbols in dynamic library:"
nm -D libmath.so | grep -E "add|subtract|multiply|factorial"
echo ""

echo "Detailed size comparison:"
size prog_static prog_dynamic
echo ""

echo "=================================================="
echo "  Summary"
echo "=================================================="
echo ""
echo "Static linking:"
echo "  ✓ Library code is copied into executable"
echo "  ✓ Larger executable size"
echo "  ✓ No runtime dependencies"
echo "  ✓ Faster execution (no dynamic loading)"
echo ""
echo "Dynamic linking:"
echo "  ✓ Library code is separate (.so files)"
echo "  ✓ Smaller executable size"
echo "  ✓ Requires library files at runtime"
echo "  ✓ Libraries can be updated independently"
echo "  ✓ Multiple programs can share libraries"
echo ""
echo "Try modifying the library code and rebuilding to"
echo "see how each linking method handles updates!"
echo "=================================================="
