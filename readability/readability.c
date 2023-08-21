#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>





int main(int argc, string argv[])
{
    // Getting input text
    string text = get_string("Text: ");
    printf("Text: %s\n", text);

    // Calculating number of letters in text
    int letters = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(((text[i]) >= 'a' && (text[i]) <= 'z') || ((text[i]) >= 'A' && (text[i]) <= 'Z'))
        letters++;

    }
    printf("%i letters\n", letters);

    //Calculating number of words in text
    int words = 1;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if((text[i]) == ' ')
        words++;

    }
    printf("%i words\n", words);

    //Calculating number of sentences in text
    int sentences = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        sentences++;

    }
    printf("%i sentences\n", sentences);

    //Using Coleman-Liau formula to calculate the grade of the text
    int L = letters/words*100
    int S = sentences/words*100
    int X = 0.0588 * L - 0.296 * S - 15.8
    if(index)

    printf("Grade: %i\n", X)

}

