#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    string key = argv[1];

    //Check the key
    if(key == 0)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }


    for(int i = 0, n = strlen(key); i < n; i++)
    {
        if(!isalpha(key[i])
        {

        printf("Key must contain alphabetic characters\n");

        return 1;
        }
    }


    if(argv[strlen] != 26 )
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    //Receive input
    string plaintext = get_string("plaintext: ");

    //Check the input
}