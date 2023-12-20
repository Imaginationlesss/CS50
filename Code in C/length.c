#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctyope.h>

int main (void)
{
    string name =get_string("What's your name? ");

    int n = strlen(name);

    printf("%i\n", n);


}