#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef


int factorial(int number);

int mainc (void)
{
    // Prompt use for number
    int n = get_int("Type a number ");
    printf("%i\n", factorial(n));
}

int factorial(int number)
{
    if(number == 1)
    {
        return 1;
    }

    return number * factorial(number - 1);
}