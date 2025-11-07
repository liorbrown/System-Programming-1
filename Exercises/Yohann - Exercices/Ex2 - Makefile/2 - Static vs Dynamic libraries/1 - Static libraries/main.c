#include <stdio.h>
#include "calculator.h"

/**
 * STATIC LIBRARY EXAMPLE
 *
 * Static libraries (.a files) are archives of object files.
 * The library code is COPIED into the executable at link time.
 *
 * Steps to create and use:
 * 1. Compile source to object file:  gcc -c calculator.c -o calculator.o
 * 2. Create archive (static lib):    ar rcs libcalculator.a calculator.o
 * 3. Link with program:              gcc main.c -L. -lcalculator -o prog
 */

int main()
{
    printf("=== STATIC LIBRARY DEMO ===\n\n");

    printf("Using calculator library (STATIC):\n");
    printf("  5 + 3 = %d\n", add(5, 3));
    printf("  5 * 3 = %d\n", multiply(5, 3));

    printf("\nNote: The library code is embedded in this executable.\n");
    printf("The .a file is NOT needed to run this program.\n");

    return 0;
}
