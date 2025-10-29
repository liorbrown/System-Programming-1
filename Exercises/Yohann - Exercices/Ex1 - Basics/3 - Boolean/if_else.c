#include <stdio.h>
#include <string.h>

/*
 * Demonstrates use of if, else if, and else in multiple situations.
 */

void example_simple_if_else(void)
{
    int a = 5, b = 10;
    printf("Example 1 - simple if / else:\n");
    if (a > b)
    {
        printf("  %d is greater than %d\n", a, b);
    }
    else
    {
        printf("  %d is not greater than %d\n", a, b);
    }
    puts("");
}

void example_else_if_chain(void)
{
    int score = 76;
    printf("Example 2 - else if chain (grading):\n");
    if (score >= 90)
    {
        printf("  Grade: A\n");
    }
    else if (score >= 80)
    {
        printf("  Grade: B\n");
    }
    else if (score >= 70)
    {
        printf("  Grade: C\n");
    }
    else if (score >= 60)
    {
        printf("  Grade: D\n");
    }
    else
    {
        printf("  Grade: F\n");
    }
    puts("");
}

void example_nested_if(void)
{
    int age = 20;
    int has_id = 1; /* 1 = true, 0 = false */
    printf("Example 3 - nested if (eligibility check):\n");
    if (age >= 18)
    {
        if (has_id)
        {
            printf("  Eligible: age %d and ID present\n", age);
        }
        else
        {
            printf("  Not eligible: age %d but no ID\n", age);
        }
    }
    else
    {
        printf("  Not eligible: underage (%d)\n", age);
    }
    puts("");
}

void example_logical_conditions(void)
{
    int x = -3;
    printf("Example 4 - logical operators in if conditions:\n");
    if (x > 0)
    {
        printf("  x is positive\n");
    }
    else if (x < 0 && (x % 2) != 0)
    {
        printf("  x is negative and odd\n");
    }
    else
    {
        printf("  x is zero or negative even\n");
    }
    puts("");
}

int main(void)
{
    example_simple_if_else();
    example_else_if_chain();
    example_nested_if();
    example_logical_conditions();
    return 0;
}