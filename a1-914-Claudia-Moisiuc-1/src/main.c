#include <stdio.h>
extern void numbers(int number);
extern void subsequence(int v[], int number);
extern void values(int number);

void read_array(int number, int v[])
{int i;
    for (i=1; i<=number; i++)
        scanf("%d", &v[i]);

}

void menu() {///The function prints the menu of the program
    int number, v[100], ok, array=0, lab=12;
    char option;
    printf("MENU:\n");
    printf("1. Read a vector.\n");
    printf("2. Decompose a given even natural number, greater than 2, as a sum of two prime numbers (Goldbach’s conjecture).\n");
    printf("3. Given a vector of numbers, find the longest contiguous subsequence such that any consecutive elements have at least 2 distinct digits in common.\n");
    printf("4. Determine all the numbers smaller than a given natural and non-null number n and that are relatively prime to n.\n");
    printf("5. Exit the program\n");

    ok = 1;
    while (ok == 1) {
        printf("\n Option:  ");
        scanf("%d", &option);
        switch (option) {
            case 1: //Vector reading
                printf("Number of numbers in the array:  ");
                scanf("%d", &array);
                read_array(array, v);
                v[0] = array;
                break;
            case 2: //Sub a
                printf("Number for decomposing:  ");
                scanf("%d", &number);
                numbers(number);
                break;
            case 3: //Sub b
                subsequence(v, v[0]);
                break;
            case 4: //lab
                printf("Number to read:  ");
                scanf("%d", &lab);
                values(lab);
                break;
            case 5: //Exit
                ok = 0;
                break;
            default:
                printf("Invalid input");}
        /*if (option == 1) {
            printf("Number of numbers in the array:  ");
            scanf("%d", &array);
            read_array(array, v);
            v[0]=array;
        }
        else if(option == 2)
        {
            printf("Number for decomposing:  ");
            scanf("%d", &number);
            numbers(number);
        }
        else if(option == 3)
            subsequence(v, v[0]);
        else if (option == 4)
            ok=0;
        else
            printf("Invalid input");*/

}}

int main()
{
    menu();
    return 0;
}

