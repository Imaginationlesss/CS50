#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a = 28;
    int b = 50;
    int *c = &a;

    *c = 14; &a = 14
    c = &b;   c = 50
    *c = 25;

    // Print results
    printf("a has the value %i, located at %p\n", a, &a);  20  28
    printf("b has the value %i, located at %p\n", b, &b);
    printf("c has the value %p, located at %p\n", c, &c);
}


