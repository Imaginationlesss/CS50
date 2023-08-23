#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key = argv[1];

    // Check the key
    if (key == 0)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain alphabetic characters\n");
            return 1;
        }
    }

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (tolower(key[i]) == tolower(key[j]) || toupper(key[i]) == toupper(key[j]))
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }

    // Receive input
    string plaintext = get_string("plaintext: ");

    // Transform into cipertext

    printf("cipertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        int difference = 0;
        if (isupper(plaintext[i]))
        {
            difference += plaintext[i] - 65;
            printf("%c", key[difference]);
        }
        else if (islower(plaintext[i]))
        {
            difference += plaintext[i] - 97;
            printf("%c", key[difference] + 32);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;

    // VCHPRZGJNTLSKFBDQWAXEUYMOI
    // ABCDEFGHIJKLMNOPQRSTUVWXYZ

    // for each character in plaintext
    // find corresponding character in key
    // add corresponding character to ciphertext
}