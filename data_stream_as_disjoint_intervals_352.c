/* Leetcode - 352. Data Stream as Disjoint Intervals (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20

void reset ();
void green ();
void yellow ();
void red ();

void addNum(int *array, int *arraySize, int element);
void sortArray(int *array, int arraySize);
void getIntervals(int *array, int arraySize);

int main()
{
    yellow();

    printf("Leetcode - 352. Data Stream as Disjoint Intervals (C language) - ");

    red();

    printf("Hard\n");

    int ranges[ARRAY_SIZE] = {};
    int rangesSize = 0;

    green();

    printf("Test 1: \n");

    reset();

    addNum(ranges, &rangesSize, 1);
    getIntervals(ranges, rangesSize);

    addNum(ranges, &rangesSize, 3);
    getIntervals(ranges, rangesSize);
    
    addNum(ranges, &rangesSize, 7);
    getIntervals(ranges, rangesSize);

    addNum(ranges, &rangesSize, 2);
    getIntervals(ranges, rangesSize);

    addNum(ranges, &rangesSize, 6);
    getIntervals(ranges, rangesSize);

    printf(" | ");

    green();

    printf("Passed\n");

    reset();

    return 0;
}

void getIntervals(int *array, int arraySize)
{
    if (arraySize == 0) return;
    
    int starter = array[0];

    for (int i = 0; i < arraySize - 1; i++) 
    {
        if (array[i + 1] - array[i] != 1)
        {
            printf("{%i %i} ", starter, array[i]);
            starter = array[i + 1];
        }
    }
    printf("{%i %i}\n", starter, array[arraySize - 1]); 
}


void sortArray(int *array, int arraySize)
{
    int c = 0;
    bool flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < arraySize - 1 - c; i++)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                flag = true;
            }
        }
        
        c++;
    }
}

void addNum(int *array, int *arraySize, int element)
{
    array[*arraySize] = element;
    (*arraySize)++;
    sortArray(array, *(arraySize));
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