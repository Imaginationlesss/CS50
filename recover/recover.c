#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *inp = fopen(argv[1], "r");
    if (inp == NULL)
    {
        printf("Could not open %s.\n", inp);
        return 1;
    }

    while (fread(buffer, 1, 512, card))
    {

    }

    int image_counter = 0;
    char *buffer[BLOCK_SIZE];

}