#include <assert.h>
#include <stdio.h>

int divide(int numerator, int denumerator)
{
    assert(denumerator != 0);
    return numerator / denumerator;
}

int main(void)
{

    int x = 5, y = 10;
    int res = divide(x, y);
    printf("%d", res);

    y = 0;
    res = divide(x, y);
    printf("%d", res);
}