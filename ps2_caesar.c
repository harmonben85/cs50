#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) // Check if there is exactly one value entered for the key.
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int n = 0; n < strlen(argv[1]); n++) // Check if the key value is a number.
    {
        if (!isdigit(argv[1][n]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]); // Convert the key from string to integer data type.

    string plaintext = get_string("plaintext:  "); // Ask the user for a message.
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        int ciphertext[strlen(plaintext)];
        int pt_number = plaintext[i];

        if (isupper(plaintext[i])) // Encrypt the uppercase characters.
        {
            ciphertext[i] = (((pt_number - 65) + key) % 26) + 65; // Shift 65 because of ASCII values of uppercase letters.
        }

        else if (islower(plaintext[i])) // Encrypt the lowercase characters
        {
            ciphertext[i] = (((pt_number - 97) + key) % 26) + 97; // Shift 97 because of ASCII values of lowercase letters.
        }

        else
        {
            ciphertext[i] = pt_number; // Do not shift characters that are non-alphabetical.
        }

        printf("%c", ciphertext[i]); // Print out the cipher text.
    }
    printf("\n");
}
