#include <stdio.h>
#include "calculator.h"

/**
 * DYNAMIC LIBRARY EXAMPLE
 *
 * Dynamic/Shared libraries (.so files) are loaded at runtime.
 * The library code is NOT copied into the executable.
 *
 * Steps to create and use:
 * 1. Compile with PIC:  gcc -fPIC -shared calculator.c -o libcalculator.so
 * 2. Link with program: gcc main.c -L. -lcalculator -Wl,-rpath,. -o prog
 * 3. Run (needs .so):   ./prog
 */

int main()
{
    printf("=== DYNAMIC LIBRARY DEMO ===\n\n");

    printf("Using calculator library (DYNAMIC):\n");
    printf("  7 + 2 = %d\n", add(7, 2));
    printf("  7 * 2 = %d\n", multiply(7, 2));

    printf("\nNote: The library code is in libcalculator.so\n");
    printf("The .so file MUST be present to run this program.\n");
    printf("Try deleting libcalculator.so and running again!\n");

    return 0;
}
