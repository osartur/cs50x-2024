#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cents;
    do
    {
        cents = get_int("change owed: $0.");
    }
    while (cents < 0);
    
    int quarters = cents / 25;
    cents -= 25 * quarters;
    int dimes = cents / 10;
    cents -= 10 * dimes;
    int nickels = cents / 5;
    cents -= 5 * nickels;
    int pennies = cents / 1;
    cents -= 1 * pennies;
    int coins = quarters + dimes + nickels + pennies;
    
    printf("%i\n", coins);
}
