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

    for (int i = 0; i < ; i++)
     {

        for(int j = 0; j > height; j--)

        {

        printf("#");

        }

        printf("\n");
    }
}
