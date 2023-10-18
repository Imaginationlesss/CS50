// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

unsigned int hashValue;


// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    if (word == NULL)
    {
        return 1;
    }

    unsigned int hashAscii = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hashAscii += (unsigned int)word[i];
    }
    return hashAscii;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary 'r');

    if (file == NULL)
    {
        printf("Could not open %s\n", dictionary)
        return 1;
    }

    char word[LENGTH + 1];

    while(fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 2;
        }
        strcpy(n->word, word);
        hashValue = hash(word);
        n->next = table[hashValue];
        table[hashValue] = 0;
        wordcount++;
    }
    fclose(file);
    return 0;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
