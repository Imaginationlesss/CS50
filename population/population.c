#include <cs50.h>
#include <stdio.h>

int main(void)

{

    // TODO: Prompt for start size
    int n;
    {
        n = get_int("Starting Size: ");
    }
    while (n < 9);

    // TODO: Prompt for end size

    int m;
    do
    {
        m = get_int("End Size: ");
    }
    while (m < n);

    // TODO: Calculate number of years until we reach threshold

    int years = 0;
    do
    {
        n += n / 3;
        n += n / 4;
        years++;
    }
    while (n < m);
    // TODO: Print number of years

    printf("Years: %i\n", years);
}
