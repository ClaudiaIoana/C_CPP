//
// Created by dell on 22.02.2022.
//
///Given a vector of numbers, find the longest contiguous subsequence such that any consecutive elements have at least 2 distinct digits in common.
#include <stdio.h>

int common_digits(int nr1, int nr2)
{///The function creates characteristic vectors for every given number and searches if the numbers have at lest 2 distinct common digits
    int vect1[10] = {0}, vect2[10] = {0}, i, distinct = 0;
    while (nr1 != 0)
    {
        vect1[nr1%10]++;
        nr1 = nr1/10;
    }
    while (nr2 != 0)
    {
        vect2[nr2%10]++;
        nr2 = nr2/10;
    }

    for (i = 0; i<=10; i++)
        if (vect1[i] !=0 && vect2[i] !=0)
            distinct++;

    if (distinct >= 2)
        return 1;
    return 0;
}


void print(int first, int last, int v[])
{///The function prints the longest subsequence if there is one, and a message otherwise
    if (first == last)
    {
        printf("no subsequence");
        return;
    }
    for (int i=first; i<=last; i++)
        printf("%d ", v[i]);
}

void subsequence(int v[], int length)
{///The function searches for the longest subsequence that exists in the array and sends for printing the starting and the end point of the subsequence
    int i, long_secv=0, start=1, final_last=0, final_start=1;
    for(i=1; i<length; i++)
    {
        if (common_digits(v[i], v[i+1])==0)
        {
            if (final_last-final_start < long_secv-start)
            {
                final_last = start + long_secv;
                final_start = start;
            }
            long_secv = 1;
            start = i+1;

        }
        else
            long_secv++;

    }
    if (final_last-final_start < long_secv-start)
    {
        final_last = long_secv+start;
        final_start = start;
    }

    print(final_start, final_last, v);


}
