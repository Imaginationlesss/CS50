#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;

    do
    {
        
    height = get_int("Height: ");

    }
    while (height > 0 || height < 9);
}
