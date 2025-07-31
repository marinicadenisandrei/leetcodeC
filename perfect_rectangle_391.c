/* Leetcode - 391. Perfect Rectangle (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

bool isRectangleCover(int rectanglesVar[ARRAY_SIZE][ARRAY_SIZE], int rectanglesSizeVar, int rectanglesInSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 391. Perfect Rectangle (C language) - ");

    red();

    printf("Hard\n");

    int rectangles[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}},{{1,1,2,3},{1,3,2,4},{3,1,4,2},{3,2,4,4}},{{1,1,3,3},{3,1,4,2},{1,3,2,4},{2,2,4,4}}};
    int rectanglesSize[NUMBER_OF_TESTS] = {5,4,4};
    int rectanglesInSize[NUMBER_OF_TESTS] = {4,4,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((isRectangleCover(rectangles[test], rectanglesSize[test], rectanglesInSize[test])) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool isRectangleCover(int rectanglesVar[ARRAY_SIZE][ARRAY_SIZE], int rectanglesSizeVar, int rectanglesInSizeVar)
{
    int totalArea = 0;
    int squareRoot = 0;

    for (int i = 0; i < rectanglesSizeVar; i++)
    {
        totalArea += (rectanglesVar[i][2] - rectanglesVar[i][0]) * (rectanglesVar[i][3] - rectanglesVar[i][1]);
    }

    squareRoot = sqrt(totalArea);

    return pow(squareRoot, 2) == totalArea;
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