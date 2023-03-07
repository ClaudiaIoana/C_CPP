//
// Created by dell on 01.03.2022.
//
///Determine all the numbers smaller than a given natural and non-null number n and that are relatively prime to n.
#include <stdio.h>

int prime_numbers(int first, int n)
{///the function determines if the numbers are respectively prime and returns 1 if they are
    int i;
    for (i = 2; i <= first; i++)
    {
        if (n % i == 0 && first % i == 0)
            return 0;
    }
    return 1;
}

void print_value(int x)
{///the function prints the value
    printf("%d  ", x);
}

void message(int ok, int number)
{///the function prints messages if it is necessary
    if (ok == 0) // there are no values
        printf("No values that meet the requirement");
    else if (ok == 1)
        printf("The numbers smaller than n and relatively prime to %d are:  ", number);
}

void values(int number)
{///the function finds numbers and if they are prime with number prints them
    int i, ok = 0;
    for (i=2; i < number; i++)
    {
        if (prime_numbers(i, number) == 1)
        {
            ok++;
            message(ok, number);
            print_value(i);
        }

    }
}