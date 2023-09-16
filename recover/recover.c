#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
#define BLOCK_SIZE 512
bool first_jpg = false;
bool found_jpg = false;

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
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Could not open\n");
        return 1;
    }

    // Read the file of 512bytes and store into buffer until the end of the card
    int read_bytes;
    FILE *output_file = NULL;
    while ((read_bytes = fread(buffer, sizeof(BYTE), BLOCK_SIZE, input_file)) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (!first_jpg)
            {
                first_jpg = true;
            }
            else
            {
                fclose(output_file);
            }
            char output[8];
            sprintf(output, "%03i.jpg", image_counter);
            output_file = fopen(output, "w");
            if (output_file == NULL)
            {
                fclose(input_file);
                printf("Could not create the file");
                return 2;
            }
            image_counter++;
        }
        // keep writing
        if (!found_jpg)
        {
            found_jpg = true;
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output_file);
        }
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}