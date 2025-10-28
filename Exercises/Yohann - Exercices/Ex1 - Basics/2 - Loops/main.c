#include <stdio.h>

int main(void)
{
    /* Example 1: for loop - print numbers 1 through 5 */
    printf("EX1:\nfor loop: counting 1 to 5\n");

    int i = 0;
    for (int i = 1; i <= 5; i++)
    {
        printf("  i = %d\n", i);
    }

    int i = 0;
    printf("%d\n", i++);
    printf("%d\n", i);
    printf("%d\n", ++i);

    putchar('\n');

    /* Example 2: while loop - print numbers 5 down to 1 */
    printf("EX2:\nwhile loop: counting 5 down to 1\n");
    int j = 5;
    while (j > 0)
    {
        printf("  j = %d\n", j);
        --j; // manual countdown
    }

    putchar('\n');

    /* Example 3 - do while */
    printf("EX3:\nDo while");
    int f = 0;
    do
    {
        printf("%d\n", f); // this will print even tho the while condition is not met

    } while (f > 0);

    /* Example 4: demonstrate continue and break in a for loop */
    printf("EX4:\nfor loop with continue/break (1..10): show evens, stop at 8\n");
    for (int k = 1; k <= 10; k += 1)
    {
        if (k % 2 != 0)
        {
            continue; /* skip to the next loop iteration*/
        }
        if (k == 8)
        {
            printf("reached %d, breaking loop\n", k);
            break; /* exit the loop */
        }
        printf("  even k = %d\n", k);
    }
    return 0;
}