/* Leetcode - 470. Implement Rand10() Using Rand7() (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int* rand10(int nVar);
int rand7(void);
void printArr(int *arr, int arrSize);

int main()
{
    yellow();

    printf("Leetcode - 470. Implement Rand10() Using Rand7() (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {1,2,3};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int *result = rand10(n[test]);
        printArr(result, n[test]);

        green();

        printf("Passed\n");
    }

    reset();
}

void printArr(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%i%s", ((i == 0 ? "[" : "")), arr[i], ((i < arrSize - 1) ? ", " : "] | "));
    }
}

int rand7(void) {
    int limit = RAND_MAX - (RAND_MAX % 7);
    int r;

    do {
        r = rand();
    } while (r >= limit);

    return (r % 7) + 1;
}

int* rand10(int nVar)
{
    int *result = malloc((nVar) * sizeof(int));

    for (int i = 0; i < nVar; i++)
    {
        int candidate1 = rand7();
        int candidate2 = rand7();

        while (candidate1 + candidate2 > 10)
        {
            candidate1 = rand7();
            candidate2 = rand7();
        }

        result[i] = candidate1 + candidate2;
    }

    return result;
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