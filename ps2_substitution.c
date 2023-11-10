#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) // check if there is exactly one value entered for the key.
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    for (int n = 0; n < strlen(argv[1]); n++) // check if the key is alphabetical characters only
    {
        if (!isalpha(argv[1][n]))
        {
            printf("Key must consist of alphabetical characters only.\n");
            return 1;
        }
    }

    if (strlen(argv[1]) != 26) // check that key has 26 characters
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int x = 0; x < strlen(argv[1]); x++) // check for duplicates in the key
    {
        for (int y = 0; y < strlen(argv[1]); y++)

            if (argv[1][x] == argv[1][y] && x != y)
            {
                printf("There must be no duplicates in the key.\n");
                return 1;
            }
    }
    // ----------------------------------------------------------------------------------------------------------------------
    string plaintext = get_string("plaintext:  "); // Ask the user for a message.
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)

    {
        int ciphertext[strlen(plaintext)];

        if (isupper(plaintext[i]))
        {
            ciphertext[i] = toupper(argv[1][(plaintext[i] - 65)]); // maintain uppercase characters
        }

        else if (islower(plaintext[i]))
        {
            ciphertext[i] = tolower(argv[1][(plaintext[i] - 97)]); // maintain lowercase characters
        }

        else
        {
            ciphertext[i] = plaintext[i]; // do not cipher non-alphabetical characters
        }

        printf("%c", ciphertext[i]); // print the completed cipher text
    }
    printf("\n");
    return 0;
}
