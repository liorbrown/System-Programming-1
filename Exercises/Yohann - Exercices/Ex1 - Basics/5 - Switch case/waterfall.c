#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    char mychar = 'e';

    switch (mychar)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        printf("This is a vowel\n");
        break;

    default:
        printf("This is a consonant\n");
        break;
    }
}