#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int letter_values[26] = {1, 3, 3,  2, 1, 4, 2, 4, 1, 8, 5, 1,  3,
                         1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int score(string word);

int main(void)
{
    string p1_word = get_string("Player 1: ");
    string p2_word = get_string("Player 2: ");
    
    int p1_score = score(p1_word);
    int p2_score = score(p2_word);
    
    if (p1_score > p2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (p2_score > p1_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
}

int score(string word)
{
    int total = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            int letter_index = tolower(word[i]) - 'a';
            total += letter_values[letter_index];
        }
    }
    return total;
}

