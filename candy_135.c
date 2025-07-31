/* Leetcode - 135. Candy (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int candy(int *ratingsVar, int ratingsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 135. Candy (C language) - ");

    red();

    printf("Hard\n");

    int ratings[ARRAY_SIZE][ARRAY_SIZE] = {{1,0,2},{1,2,2}};
    int ratingsSize[ARRAY_SIZE] = {3,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", candy(ratings[test], ratingsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int candy(int *ratingsVar, int ratingsVarSize)
{
    int sumCand = 0;

    for (int i = 1; i < ratingsVarSize; i++)
    {
        if (ratingsVar[i - 1] == ratingsVar[i])
        {
            ratingsVar[i]--;
        }

        if (ratingsVar[i] == 0)
        {
            ratingsVar[i] += 1;

            if (ratingsVar[i - 1] == ratingsVar[i])
            {
                ratingsVar[i - 1] += 1;
            }
        }
    }

    for (int i = 0; i < ratingsVarSize; i++)
    {
        sumCand += ratingsVar[i];
    }

    return sumCand;
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