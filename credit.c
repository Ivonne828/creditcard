#import <cs50.h>
#import <stdio.h>

bool checksum(long num);

int main(void)
{
    long number = get_long("Number: ");
    long first_two = number;
    int length = 2;

    while (first_two >= 100)
    {
        first_two /= 10;
        length += 1;
    }

    // first number, for VISA
    long first_one = first_two / 10;

    if (checksum(number) == false)
    {
        printf("INVALID\n");
    }
    else
    {
        if ((first_two == 34 || first_two == 37) && length == 15)
        {
            printf("AMEX\n");
        }
        else if ((first_two == 51 || first_two == 52 || first_two == 53 || first_two == 54 || first_two == 55) && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && first_one == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

bool checksum(long num)
{
    int multiply = 0;

    for (int i = 0; num > 0; i++, num /= 10)
    {
        int digit = num % 10;

        if (i % 2 == 1)
        {
            int doubled = digit * 2;
            multiply += (doubled / 10) + (doubled % 10); // checks if it's 2 numbers or 1 number
        }
        else
        {
            multiply += digit;
        }
    }

    return multiply % 10 == 0;
}
