#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    //Check the file
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //Open the file
    FILE *inp = fopen(argv[1], "r");
    if (inp == NULL)
    {
        printf("Could not open %s.\n", inp);
        return 1;
    }

    //Read the file of 512bytes and store into buffer until the end of the card
    while (fread(buffer, 1, 512, card))
    {

    }

    int image_counter = 0;
    uint8_t buffer[BLOCK_SIZE];

}