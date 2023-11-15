#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for number between 1 and 8 inclusive with do-while loop
    int pyramid_height;

    do
    {
        pyramid_height = get_int("Please enter a height between 1 and 8:\n");
    }

    while (pyramid_height < 1 || pyramid_height > 8);

    int row, space, column;

    for (row = 0; row < pyramid_height; row++)
    {
        for (space = 0; space < pyramid_height - row - 1; space++)
        {
            printf(" ");
        }

        for (column = 0; column <= row; column++)
        {
            printf("#");
        }

        printf("  ");

        for (column = 0; column <= row; column++)
        {
            printf("#");
        }

        printf("\n");
    }
}
