#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
    start = get_int("Enter an initial size of the population: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
    end = get_int("Enter the ending size of the population: ");
    }
    while (end < start);

    if (end == start)
        printf("Years: %i\n", 0);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;

    do
    {
        start += (start/3) - (start/4);
        years++;
    }
    while (start < end);

    // TODO: Print number of years
    printf("Years: %i\n", years);
}