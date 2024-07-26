#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool is_valid_card(long long number);
string get_card_type(long long number);
bool is_american_express(int prefix, int length);
bool is_mastercard(int prefix, int length);
bool is_visa(int prefix, int length);
int get_number_length(long long n);
int add_digits(long long n);

int main(void)
{
    long long credit_card;
    do
    {
        credit_card = get_long_long("number: ");
    }
    while (credit_card < 0);
    
    if (is_valid_card(credit_card))
    {
        printf("%s\n", get_card_type(credit_card));
    }
    else
    {
        printf("INVALID\n");
    }
}

bool is_valid_card(long long number)
{
    int checksum = 0;
    int factor = 1;
    while (number > 0)
    {
        int digit = number % 10;
        checksum += add_digits(factor * digit);
        number /= 10;
        if (factor == 1)
        {
            factor = 2;
        }
        else
        {
            factor = 1;
        }
    }
    return checksum % 10 == 0;
}

string get_card_type(long long number)
{
    int length = get_number_length(number);
    int prefix = number / (long long) pow(10, length - 2);
    if (is_american_express(prefix, length))
    {
        return "AMEX";
    }
    else if (is_mastercard(prefix, length))
    {
        return "MASTERCARD";
    }
    else if (is_visa(prefix, length))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}

bool is_american_express(int prefix, int length)
{
    return length == 15 && (prefix == 34 || prefix == 37);
}

bool is_mastercard(int prefix, int length)
{
    return length == 16 && (prefix >= 51 && prefix <= 55);
}

bool is_visa(int prefix, int length)
{
    return (length == 16 || length == 13) && prefix / 10 == 4;
}

int get_number_length(long long n)
{
    int length = 0;
    while (n > 0)
    {
        length++;
        n /= 10;
    }
    return length;
}

int add_digits(long long n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
