// Ask the user for the height, then prints a "mountain" made out of hashes with the height provided

// Using the libraries "cs50.h" and "stdio.h" for "get_int" function and "printf"
#include <cs50.h>
#include <stdio.h>

// Main function:
int main(void)
{
    int n; // Height variable
    do
    {
        n = get_int("Height: "); // Asking the user for the height. Will ask nonstop if the user
                                 // dont say a number higher than 1 but lower than 8
    }
    while (n > 8 || n < 1); // The loop. We use the "do while" instead of a "while do" for the loop
                            // to be executed at least once and giving the variable 'n' a value.

    for (int i = 0; i < n;
         i++) // The variable "i" is a counter. For everytime "i" have a value "less than" the
              // variable "n" (the height), it executes the code below and adds +1 for "i" (counter)
    {
        for (int d = n - 1; d > i;
             d = d - 1) // "d" is the counter for the spaces. D will always be the height -1. This
                        // adds the effect of the column being to the right.
        {
            printf(" "); // Printing a space
        }

        for (int h = -1; h < i;
             h++) // Now the hashes. The code below will be executed everytime that the "h" (hashes)
                  // have a number less than i (counter) and will also add +1 for the "h" variable.
        {
            printf("#"); // Printing a hash
        }
        printf("\n"); // Breaking a row for every line of the column
    }
}
