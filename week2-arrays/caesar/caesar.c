#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char encrypt(char c, int k);
bool is_number(string s);

int main(int argc, string argv[])
{
    if (argc != 2 || !is_number(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");
    
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        printf("%c", encrypt(plaintext[i], key));
    }
    printf("\n");
    return 0;
}

char encrypt(char c, int k)
{
    if (!isalpha(c))
    {
        return c;
    }
    char letter_index = tolower(c) - 'a';
    int offset = (letter_index + k) % 26 - letter_index;
    return c + offset;
}

bool is_number(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

