/* Leetcode - 2. Add Two Numbers (C language) */

#include <stdio.h>
#include <stdlib.h>

int arrayToInteger(const int *array, int sizeArray);
int integerToArray(int number, int finalArray[], int sizeFinalArray);

void reset ();
void green ();
void yellow ();

int main(void)
{
    yellow(); 

    printf("Leetcode - 2. Add Two Numbers (C language)\n");

    int l1[10][20] = {{2,4,3}, {9,9,9,9,9,9,9}};
    int l2[10][20] = {{5,6,4}, {9,9,9,9}};

    int lenArrays1[10] = {3,7};
    int lenArrays2[10] = {3,4};

    for (int test = 0; test < 2; test++)
    {
        int result = arrayToInteger(l1[test], lenArrays1[test]) + arrayToInteger(l2[test], lenArrays2[test]);

        int finalArray[20];
        int sizeFinalArray = 0;

        int size = integerToArray(result, finalArray, sizeFinalArray);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("[ ");
        
        for (int i = 0; i < size; i++)
        {
            printf("%i ", finalArray[i]);
        }

        printf("]");

        green();

        printf(" | Passed\n");

        reset();
    }

    return 0;
}

int arrayToInteger(const int *array, int sizeArray)
{
    const int *parray = array;
    int createNumber = 1;
    int finalNumber = 0;

    for (int i = 0; i < sizeArray - 1; i++)
    {
        createNumber *= 10;
    }

    for (int i = 0; i < sizeArray; i++, parray++)
    {
        finalNumber += (*parray) * createNumber;
        createNumber /= 10;
    }

    return finalNumber;
}

int integerToArray(int number, int finalArray[], int sizeFinalArray)
{
    int copie = number;
    int createNumber = 1;

    int *pfinalArray = finalArray;

    while (createNumber < number)
    {
        number = (number/createNumber) % 10;
        createNumber *= 10;

        finalArray[sizeFinalArray] = number;
        sizeFinalArray++;

        number = copie;
    }

    return sizeFinalArray;
}

void reset () {
  printf("\033[1;0m");
}

void green () {
  printf("\033[1;32m");
}

void yellow () {
  printf("\033[1;33m");
}
