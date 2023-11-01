#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit); // Declare the function before int main(void).

int main(void)
{
    // Ask the user for a message.  Store the message as a string variable.
    string message = get_string("Enter a message to be interpreted by the bulbs: ");

    int i;

    // Iterate through each character in the message string.
    for (i = 0; i < strlen(message); i++)
    {
        int byte_array[] = {0, 0, 0, 0, 0, 0, 0, 0};

        // Convert each character of the string to a decimal (base 10) number.
        int decimal_num = message[i];

        int j = 0;

        while (decimal_num > 0)
        {
            byte_array[j] = decimal_num % 2; // Convert decimal to binary.
            decimal_num = decimal_num / 2; // Update the value of the decimal number.
            j++;
        }
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(byte_array[k]); // Calling the print bulb function to display the bulbs in the output.
        }
        printf("\n"); // Print a new line after each byte (8 bits) (each character in the message string)
    }
}

// Definition of print bulb function
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB"); // Bulb is off when the binary digit is 0.
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1"); // Bulb is on when the binary digit is 1.
    }
}
