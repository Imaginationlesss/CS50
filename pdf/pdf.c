#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    if ( argc != 2)
    {
        printf("Improper usage.");
        return 1;
    }

    FILE *input = fopen (argv[1], "r");

    if (input == NULL)
    {
        printf("No such file found.\n");
        return 1;
    }

    uint8_t buffer[4];

    fread(buffer, 1, 4, input);

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", buffer[i]);
    }

}