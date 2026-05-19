// Ask for the user's name and then responds "hello, user" (replaces "user" with the name provided)

// Using the libraries "cs50.h" and "stdio.h" for "get_string" function and "printf"
#include <cs50.h>
#include <stdio.h>

// The main function, expects no input or output

int main(void)
{
    // Asking for the user's name:
    string name = get_string("What is your name? ");

    // Saying hello to the user:
    printf("hello, %s\n", name);
}
