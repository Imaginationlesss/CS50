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
    int line = 0;

    do{

    for (int i = 0; i < height; i++)
     {

        printf("#");

        }

        printf("\n");

    }
    while(line < height);
}
