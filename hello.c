#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string answer1 = get_string("What is your name? ");
    string answer2 = get_string("What is your gf's name? ");
    printf("hello, %s and %s\n", answer1, answer2);
}