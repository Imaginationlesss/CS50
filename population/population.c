#include <cs50.h>
#include <stdio.h>

int main(void)

{

    // TODO: Prompt for start size
    int n = 0;
    do
    {
        n = get_int("Starting Size: ");
    }
    while (n < 9);

    // TODO: Prompt for end size

    int m = 0;
    do
    {
        m = get_int("End Size: ");
    }
    while (n > m);

    // TODO: Calculate number of years until we reach threshold
    //When cheking correctnes of code I didn't know how to fix it, when starting and ending numbers match years should show "0" insted of "1", so i used "If else" function which i know about from my previous experiense
    // with coding, which wasn't provided in first weeks lecture but it fixed the problem and code works perfectly, so I assume it's okay to use here and it will be submitter without any issues like "academic honesty".

    int years = 0;

    if (n == m)
    {

        printf("Years: %i\n", years);
        return 0;
    }
    else
    {

        do
        {
            n = n + (n / 3) - (n / 4);
            years++;
        }
        while (n < m);
    }
    // TODO: Print number of years

    printf("Years: %i\n", years);
}