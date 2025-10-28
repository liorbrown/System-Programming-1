#include <stdio.h>

int main(void)
{

    printf("%d\n", (3 == 3)); // ?

    printf("%d\n", (3 == 4)); // ?

    printf("%d\n", !(3 == 4)); // ?

    printf("Part 2 -");
    if (0)
    {
        printf("Not passing here...\n");
    }

    if (1)
    {
        printf("\n1 is passing\n");
    }

    if (30934)
    {
        printf("Any number is passing\n");
    }

    if ('a')
    {
        printf("Chars also !\n");
    }

    int *p = NULL;
    if (p)
    {
        printf("Null not printing\n");
    }

    if ('\0')
    {
        printf("Also considered 0 !\n");
    }

    if ("0")
    {
        printf("And this ?\n");
    }

    printf("\n\nPart 3 - ");
    // combining multiple booleans
    int age = 18;
    int income = 6000;
    int grade = 86;
    int male = 0;
    int female = !male;

    // men over 18
    int over_18 = age >= 18;
    int men_over_18 = male && over_18;
    printf("%d\n", men_over_18);

    // men over 18 with an income above 10,000
    int men_over_18_income_10000 = men_over_18 && (income >= 10000);
    printf("%d\n", men_over_18_income_10000);

    // men under 18 or female with grade over 90
    int men_under_18_female_g90 = (male && !over_18) || (female && grade >= 90);
    printf("%d\n", men_under_18_female_g90);

    // note: & and | (only one) are bitwise operator (for later)
}