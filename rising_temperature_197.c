/* Leetcode - 197. Rising Temperature (C++ language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
int maxTempsSize = 0;

int* risingTemperature(int *idVar, int *temperatureVar, int size);
void printArray(int *array, int arraySize);

void reset();
void green();
void yellow();
void red();


int main(void)
{   
    yellow();

    printf("Leetcode - 197. Rising Temperature (C++ language) - ");

    green();

    printf("Easy\n");

    int id[ARRAY_SIZE] = {1, 2, 3, 4};
    int temperature[ARRAY_SIZE] = {10, 25, 20, 30};
    int size = 4;

    int *result;
    result = risingTemperature(id, temperature, size);

    green();

    printf("Test 1: ");

    reset();

    printArray(result, maxTempsSize);

    green();

    printf("Passed\n");

    reset();

    free(result);

    return 0; 
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]"));
    }

    printf(" | ");
}

int* risingTemperature(int *idVar, int *temperatureVar, int size)
{
    int max = temperatureVar[0] - temperatureVar[1];
    int *maxTemps;
    maxTemps = (int *)malloc(ARRAY_SIZE * sizeof(int));
    
    for (int i = 0; i < size - 1; i++)
    {
        if (temperatureVar[i] < temperatureVar[i + 1])
        {
            maxTemps[maxTempsSize++] = idVar[i + 1];
        }
    }

    return maxTemps;
}

void reset() {
  printf("\033[1;0m");
}

void green() {
  printf("\033[1;32m");
}

void yellow() {
  printf("\033[1;33m");
}

void red() {
  printf("\033[1;31m");
}