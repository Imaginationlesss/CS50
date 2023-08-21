#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculation(int letters, int words, int sentences);



int main(void)
{
    // Getting input text
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int index = calculation(letters, words, sentences);

    if(index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if(index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade: %i\n", index);
        return 0;
    }
    }


    // Calculating number of letters in text
    int count_letters(string text){
        int letters = 0;
            for(int i = 0, n = strlen(text); i < n; i++)
            {
                if(((text[i]) >= 'a' && (text[i]) <= 'z') || ((text[i]) >= 'A' && (text[i]) <= 'Z'))
                letters++;

            }
        return letters;
    }

    //Calculating number of words in text
    int count_words(string text){
        int words = 1;
            for(int i = 0, n = strlen(text); i < n; i++)
            {
                if((text[i]) == ' ')
                words++;
            }
        return words;
    }

    //Calculating number of sentences in text
    int count_sentences(string text){
        int sentences = 0;
            for(int i = 0, n = strlen(text); i < n; i++)
            {
                if(text[i] == '.' || text[i] == '?' || text[i] == '!')
                sentences++;

            }
            return sentences;
    }

    //Using Coleman-Liau formula to calculate the grade of the text
    int calculation(int letters, int words, int sentences)
    {
        float L = letters/words*100;
        float S = sentences/words*100;
        float index = 0.0588 * L - 0.296 * S - 15.8;

        int X = round(index);

        return X;
    }

