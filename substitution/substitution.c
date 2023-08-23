#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    //Check the key
    if(argv[1] == 0)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    else if(argc != isalpha )
    {
        printf("Key must contain alphabetic characters\n");
        return 1;
    }
    else if(argc < 26 )
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    //Receive input
    string plaintext = get_string("plaintext: ");

    //Check the input
}