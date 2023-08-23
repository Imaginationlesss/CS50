#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    string key = argv[1];

    //Check the key
    if (key == 0)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
        printf ("Key must contain alphabetic characters\n");
        return 1;
        }
    }


    if (strlen(key) != 26 )
    {
        printf ("Key must contain 26 characters\n");
        return 1;
    }

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (tolower(key[i]) == tolower(key[j]) || toupper(key[i]) == toupper(key[j]))
            {
            printf ("Key must not contain repeated characters\n");
            return 1;
            }
        }
    }
    //Receive input
    string plaintext = get_string ("plaintext: ");

    string cipertext = 0;

    //Transform into cipertext

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if(plaintext[i] == key[i])
        {
            cipertext +=plaintext[i] + key[i];
        }
    }

    printf("cipertext: %s\n", cipertext);
    return 0;


    //for each character in plaintext
    //find corresponding character in key
    //add corresponding character to ciphertext
}