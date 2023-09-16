#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;
#define BLOCK_SIZE 512
bool first_jpg = false;
bool found_jpg = false;

int image_counter = 0;
BYTE buffer[BLOCK_SIZE];
FILE *output_file = NULL;


int main(int argc, char *argv[])
{
    //Check the file
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //Open the file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Could not open\n");
        return 1;
    }

    //Read the file of 512bytes and store into buffer until the end of the card
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, input))
    {

        int read_bytes = fread(buffer, sizeof(BYTE), BLOCK_SIZE, input);
        if (read_bytes == 0)
        {
            break;
        }

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
            image_counter++;

            FILE *output_file = NULL;
            sprintf(output, "%03i.jpg", image_counter);
            output_file = fopen(output, "w")
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output_file)
        }
        else
        {
            //keep writing
            if (!found_jpg)
            {
                found_jpg = true;
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output_file);
            }
        }
    }
    fclose(output);
    return 0;

}