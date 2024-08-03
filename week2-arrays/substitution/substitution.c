#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char encrypt(char c, string map);
bool is_alphabetical(string s);
bool has_duplicates(string s);
int count(char c, string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if (!is_alphabetical(argv[1]))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    if (has_duplicates(argv[1]))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    
    string plaintext = get_string("plaintext:  ");
    
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        printf("%c", encrypt(plaintext[i], argv[1]));
    }
    printf("\n");
    
    return 0;
}

char encrypt(char c, string map)
{
    if (!isalpha(c))
    {
        return c;
    }
    int letter_index = tolower(c) - 'a';
    if (isupper(c))
    {
        return toupper(map[letter_index]);
    }
    return tolower(map[letter_index]);
}

bool is_alphabetical(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

bool has_duplicates(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (count(s[i], s) > 1)
        {
            return true;
        }
    }
    return false;
}

int count(char c, string s)
{
    int char_count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)
        {
            char_count++;
        }
    }
    return char_count;
}

