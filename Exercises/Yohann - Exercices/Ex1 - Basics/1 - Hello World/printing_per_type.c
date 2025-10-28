#include <stdio.h>
#include <stddef.h> // for size_t, ptrdiff_t
#include <stdint.h> // for fixed-width types like int32_t

/* A list of all the types and how to print them*/
int main(void)
{
    char c = 'A';
    unsigned char uc = 200;
    short s = -123;
    unsigned short us = 123;
    int i = -12345;
    unsigned int ui = 12345;
    long l = -1234567L;
    unsigned long ul = 1234567UL;
    long long ll = -1234567890123LL;
    unsigned long long ull = 1234567890123ULL;

    float f = 3.14f;
    double d = 3.14159265;
    long double ld = 3.141592653589793238L;

    size_t st = sizeof(int);
    ptrdiff_t pt = (char *)&d - (char *)&f;
    void *p = &i;

    // ---- Character types ----
    printf("char:               %c\n", c);
    printf("unsigned char:      %u\n", uc); // prints numeric value

    // ---- Integer types ----
    printf("short:              %hd\n", s);
    printf("unsigned short:     %hu\n", us);
    printf("int:                %d\n", i);
    printf("unsigned int:       %u\n", ui);
    printf("long:               %ld\n", l);
    printf("unsigned long:      %lu\n", ul);
    printf("long long:          %lld\n", ll);
    printf("unsigned long long: %llu\n", ull);

    // ---- Floating-point types ----
    printf("float:              %f\n", f);
    printf("double:             %lf\n", d);
    printf("long double:        %Lf\n", ld);

    // ---- Size and pointer difference types ----
    printf("size_t:             %zu\n", st);
    printf("ptrdiff_t:          %td\n", pt);

    // ---- Pointers ----
    printf("void*:              %p\n", p);
    return 0;
}