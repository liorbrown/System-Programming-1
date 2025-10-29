#include <stdio.h>

int main(void)
{
    int choice;

    printf("Enter a number (1-4): ");
    if (scanf("%d", &choice) != 1) // scanf returns 1 if successful,
                                   // 0 if the input doesn't match the format,
                                   // and EOF (-1) on input failure or end-of-file.
    {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    switch (choice)
    {
    case 1:
        printf("You chose 1\n");
        break;
    case 2:
        printf("You chose 2\n");
        break;
    case 3:
        printf("You chose 3\n");
        break;
    case 4:
        printf("You chose 4\n");
        break;
    default:
        printf("Number not in range 1-4\n");
        break;
    }

    return 0;
}