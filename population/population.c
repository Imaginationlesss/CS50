#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // TODO: Prompt for start size
    int n;
    do
    {
        n = get_int ("Starting Size: ");
    }
    while (n < 9);

    // TODO: Prompt for end size

    int m;
    do
    {
        m = get_int ("End Size: ");
    }
    while (m < n);

    // TODO: Calculate number of years until we reach threshold

    int upscale;

    do{
        upscale = n + (n/3) - (n/4);
    }
    while (upscale < m);

    // TODO: Print number of years

    printf("Years %i\n", upscale);
}
