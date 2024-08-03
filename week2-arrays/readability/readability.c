#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int reading_level(string text);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string prompt = get_string("Text: ");
    int grade = reading_level(prompt);
    
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    
    return 0;
}

int reading_level(string text)
{
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    
    float L = letters / (words / 100.f);
    float S = sentences / (words / 100.f);
    float index = 0.0588f * L - 0.296f * S - 15.8f;
    int level = index + 0.5f;
    return level;
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    // Check if the text is empty
    if (text[0] == '\0')
    {
        return 0;
    }
    
    int words = 1;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

