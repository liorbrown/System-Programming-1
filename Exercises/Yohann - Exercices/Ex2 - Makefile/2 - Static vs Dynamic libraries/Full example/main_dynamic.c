#include <stdio.h>
#include "mathlib.h"
#include "stringlib.h"

/**
 * Program demonstrating DYNAMIC library linking
 *
 * Dynamic libraries (.so files on Linux, .dll on Windows) are linked at runtime.
 * The library code is NOT copied into the executable.
 *
 * Advantages:
 * - Smaller executable size
 * - Library can be updated without recompiling the program
 * - Multiple programs can share same library in memory
 * - Saves disk space and memory
 *
 * Disadvantages:
 * - Slightly slower (runtime linking overhead)
 * - Requires library file to be present at runtime
 * - Potential version conflicts (DLL hell)
 */

int main()
{
    printf("=== DYNAMIC LIBRARY DEMO ===\n\n");

    // Test math library functions
    printf("Math Library Functions:\n");
    printf("  20 + 8 = %d\n", add(20, 8));
    printf("  20 - 8 = %d\n", subtract(20, 8));
    printf("  20 * 8 = %d\n", multiply(20, 8));
    printf("  Factorial(6) = %d\n", factorial(6));

    printf("\n");

    // Test string library functions
    printf("String Library Functions:\n");

    char str1[] = "dynamic linking";
    printf("  Original string: '%s'\n", str1);
    printf("  Length: %d\n", str_length(str1));

    str_to_upper(str1);
    printf("  Uppercase: '%s'\n", str1);

    char str2[] = "shared";
    printf("  Original: '%s'\n", str2);
    str_reverse(str2);
    printf("  Reversed: '%s'\n", str2);

    printf("\n");
    printf("Note: This program is linked with DYNAMIC libraries\n");
    printf("The library code is loaded from .so files at runtime.\n");

    return 0;
}
