// Become familiar wih C syntax
// Learn to debug buggy code

#include <cs50.h>

int main(void)
{
    int name;
    int location;
    // Ask for your name and where live
    name = get_string("What is your name? ");
    location = get_string("Where do you live? ");

    // Say hello
    printf("Hello, %i, from %i!", name, location);
}
