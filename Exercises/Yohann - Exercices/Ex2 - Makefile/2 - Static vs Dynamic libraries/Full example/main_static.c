#include <stdio.h>
#include "mathlib.h"
#include "stringlib.h"

/**
 * Program demonstrating STATIC library linking
 *
 * Static libraries (.a files) are linked at compile time.
 * The library code is copied into the executable.
 *
 * Advantages:
 * - Faster execution (no runtime linking overhead)
 * - No dependency on external library files at runtime
 * - Executable is self-contained
 *
 * Disadvantages:
 * - Larger executable size
 * - If library is updated, must recompile the program
 * - Multiple programs using same library waste memory
 */

int main()
{
    printf("=== STATIC LIBRARY DEMO ===\n\n");

    // Test math library functions
    printf("Math Library Functions:\n");
    printf("  10 + 5 = %d\n", add(10, 5));
    printf("  10 - 5 = %d\n", subtract(10, 5));
    printf("  10 * 5 = %d\n", multiply(10, 5));
    printf("  Factorial(5) = %d\n", factorial(5));

    printf("\n");

    // Test string library functions
    printf("String Library Functions:\n");

    char str1[] = "hello world";
    printf("  Original string: '%s'\n", str1);
    printf("  Length: %d\n", str_length(str1));

    str_to_upper(str1);
    printf("  Uppercase: '%s'\n", str1);

    char str2[] = "reverse";
    printf("  Original: '%s'\n", str2);
    str_reverse(str2);
    printf("  Reversed: '%s'\n", str2);

    printf("\n");
    printf("Note: This program is linked with STATIC libraries\n");
    printf("The library code is embedded in the executable.\n");

    return 0;
}
