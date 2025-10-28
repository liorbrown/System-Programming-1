#include <stdio.h>

int main(void)
{
    int x = 10, y = 8, z = 12;

    if (x >= y && x >= z)
        printf("Largest = %d\n", x);
    else if (y >= x && y >= z)
        printf("Largest = %d\n", y);
    else
        printf("Largest = %d\n", z);

    return 0;
}
