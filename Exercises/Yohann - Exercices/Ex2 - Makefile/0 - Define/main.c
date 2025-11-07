#include <stdio.h>
#include "foo.h"

#define NAME "Yohann"
#define SQUARE(x) (x) * (x)
// #define DEBUG // try to comment or uncomment this
#define TRUE 1
#define FALSE 0
/*
###
gcc -c foo.c -o foo.o
gcc -c main.c -o main.o
gcc main.o foo.o -o prog

###
gcc -E main.c

What we will see ?*/

int main(void)
{
    int res = SQUARE(3 + 1); // -> 3 + 1 * 3 + 1
    foo(res);
    printf("Hello %s!\n", NAME);

    int x = 20;
    int flag = (x < 20) ? TRUE : FALSE;

#ifdef DEBUG
    printf("Debug mode ON\n");
#endif

    return 0;
}
