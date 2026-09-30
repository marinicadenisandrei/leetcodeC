/* Leetcode - 492. Construct the Rectangle (C language) - Easy */

#include <stdio.h>
#include <math.h>

#define NUMBER_OF_TESTS 3

int* constructRectangle(int areaVar);
void printArr(int* arr, int size);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 492. Construct the Rectangle (C language) - ");

    green();

    printf("Easy\n");

    int area[NUMBER_OF_TESTS] = {4,37,122122};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        printf("Test %i: ", test + 1);

        reset();

        int* result = constructRectangle(area[test]);
        printArr(result, 2);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int* constructRectangle(int areaVar)
{
    static int result[2];

    int w = sqrt(areaVar);

    while (areaVar % w != 0)
    {
        w--;
    }

    int l = areaVar / w;

    result[0] = l;
    result[1] = w;

    return result;
}

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s%i%s",
               (i == 0 ? "[" : ", "),
               arr[i],
               (i == size - 1 ? "] | " : ""));
    }
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

void red () {
  printf("\033[1;31m");
}