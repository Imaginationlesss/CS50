#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Getting the height input
    int height = 0;

    do
    {

    height = get_int("Height: ");

    }
    while (height < 1 || height > 8);

    // Drawing the pirymid'

    int block = height - (height - 1);

    for (int i = 0; i < height; i++)
     {

        do{

        printf("#");
        printf("\n");

        }
        while (block < height);

    }
}
