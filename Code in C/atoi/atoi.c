#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    int num_length = strlen(input);

    if (num_length == 1)
    {
        return input[0] - '0';
    }

    char lastdgt = input[num_length - 1];

    int converted = lastdgt - '0';

    input[num_length - 1] = '\0';

    return converted + (10 * convert(input));
}