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
    count_letters;
    count_words;
    count_sentences;
    calculationl

    // Calculating number of letters in text
    int count_letters(string){
    int letters = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(((text[i]) >= 'a' && (text[i]) <= 'z') || ((text[i]) >= 'A' && (text[i]) <= 'Z'))
        letters++;

    }
    }

    //Calculating number of words in text
    int words = 1;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if((text[i]) == ' ')
        words++;

    }

    //Calculating number of sentences in text
    int sentences = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        sentences++;

    }

    //Using Coleman-Liau formula to calculate the grade of the text
    float L = letters/words*100;
    float S = sentences/words*100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    int X = round(index);

    printf("Grade: %i\n", X);

}

