#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for number between 1 and 8 inclusive with do-while loop
    int pyramid_height;
    do
    {
        pyramid_height = get_int("Please enter a height between 1 and 8.:\n ");
    }
    while (pyramid_height < 1 || pyramid_height > 8);

    // Build the pyramid using nested for loops
    int x = 1;
    int y = 1;

    for (int i = 0; i < pyramid_height; i++)
    {
        for (int k = pyramid_height - x; k > 0; k--)
        {
            printf(" ");
        }
        for (int line = y; line > 0; line--)
        {
            printf("#");
        }
        x++;
        y++;
        for (int j = 0; j < pyramid_height; j++)
        {
        }
        printf("\n");
    }
}