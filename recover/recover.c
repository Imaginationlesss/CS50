#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
#define BLOCK_SIZE 512

bool found_jpg = false;
char output[8];
int image_counter = 0;
BYTE buffer[BLOCK_SIZE];

int main(int argc, char *argv[])
{
    // Check the file
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    // Open the file
    char *card = argv[1];
    FILE *input_file = fopen(card, "r");
    if (input_file == NULL)
    {
        printf("Could not open\n");
        return 1;
    }

    // Read the file of 512bytes and store into buffer until the end of the card
    FILE *output_file = NULL;

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, input_file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (found_jpg)
            {
                fclose(output_file);
            }
            else
            {
                found_jpg = true;
            }
            sprintf(output, "%03i.jpg", image_counter);
            output_file = fopen(output, "w");
            if (output_file == NULL)
            {
                printf("Could not create the file%s\n", output);
                fclose(input_file);
                return 2;
            }
            image_counter++;
        }
        // keep writing
        if (found_jpg)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output_file);
        }
    }

    fclose(input_file);

    if (found_jpg)
    {
        fclose(output_file);
    }

    return 0;
}