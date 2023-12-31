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
    uint8_t signature[] = {37, 80, 68, 70};

    fread(buffer, 1, 4, input);

    for (int i = 0; i < 4; i++)
    {
        if(buffer[i] != signature[i])
        {
            printf("Likely not a pdf.\n");
            return 0;
        }
    }
    printf("Likely a pdf.\n");
    return 0;
}