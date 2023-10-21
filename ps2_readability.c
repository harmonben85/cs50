#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float coleman_liau(float num_letters, float num_words, float num_sentences);

int main(void)
{
    int x;
    string text = get_string("Text: ");
    x = coleman_liau(count_letters(text), count_words(text), count_sentences(text));
    if (x > 16)
    {
        printf("Grade 16+\n");
    }
    else if (x < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", x);
    }
}

// Creating a function to count the number of letters in the text.
int count_letters(string text)
{
    int i;
    float letterct = 0;
    for (i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letterct += 1;
        }
    }
    return letterct;
}

// Creating a function to count the number of words in the text.
int count_words(string text)
{
    int i;
    float wordct = 1;
    for (i = 0; i < strlen(text); i++)
    {
        if (isblank(text[i]))
        {
            wordct += 1;
        }
    }
    return wordct;
}

// Creating a function to count the number of sentences in the text.
int count_sentences(string text)
{
    int i;
    float sentencect = 0;
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentencect += 1;
        }
    }
    return sentencect;
}
// Creating a function to calculate the coleman-liau formula.
float coleman_liau(float num_letters, float num_words, float num_sentences)
{
    float L;
    float S;
    float coleman_index;
    L = (num_letters / num_words) * 100;
    S = (num_sentences / num_words) * 100;
    coleman_index = round(.0588 * L - .296 * S - 15.8);
    return coleman_index;
}