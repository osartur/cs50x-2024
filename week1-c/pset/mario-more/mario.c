#include <cs50.h>
#include <stdio.h>

void print_row(int space_count, int brick_count);

int main(void)
{
    int height;
    do
    {
       height = get_int("height: ");
    }
    while (height < 1 || height > 8);
    
    for (int i = 1; i <= height; i++)
    {
        print_row(height - i, i);
        print_row(2, i);
        printf("\n");
    }
}

void print_row(int space_count, int brick_count)
{
    for (int i = 0; i < space_count; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < brick_count; i++)
    {
        printf("#");
    }
}
