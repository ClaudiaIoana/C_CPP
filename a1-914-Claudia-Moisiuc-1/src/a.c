//
// Created by dell on 22.02.2022.
//
///Decompose a given even natural number, greater than 2, as a sum of two prime numbers (Goldbach’s conjecture)
#include <stdio.h>

int prime(int number)
{///The function verifies if a number is prime, returning 1 if it is
    int i;
    if (number <= 1)
        return 0;
    for(i=2; i<number; i++)
        if (number % i == 0)
            return 0;
    return 1;
}

void printing(int val, int val2, int number)
{///The function prints the values of the decomposition
    printf("%d + %d == %d\n", val, val2, number);
}

void numbers(int number)
{///The function determines the pair of numbers that are the decomposition of a given number
    int val, val2;
    for (val=2; val < number; val++)
        if(prime(val) == 1) {
            val2 = number - val;
            if (prime(val2) == 1)
                {printing(val, val2, number);
                return;}
        }
}


