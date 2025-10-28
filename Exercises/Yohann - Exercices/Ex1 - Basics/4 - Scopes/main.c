#include <stdio.h>
void print_x();

/* What is the output of the following snippet ? */

int x = 10;

int main(void)
{
    printf("%d\n", x); //
    int x = 20;

    printf("%d\n", x); //
    {
        printf("%d\n", x); //
        int x = 30;
        printf("%d\n", x); //
    }
    printf("%d\n", x); //

    print_x(100);
}

void print_x(int x)
{
    printf("%d\n", x); //
}
