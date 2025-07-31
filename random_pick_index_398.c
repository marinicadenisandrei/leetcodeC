/* Leetcode - 398. Random Pick Index (C++ language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 20

void reset ();
void green ();
void yellow ();
void red ();

int pick(int* arrayVar, int arraySizeVar, int targetVar);
int rand_between(int min, int max);

int main(void)
{
    yellow();

    printf("Leetcode - 398. Random Pick Index (C++ language) - Medium\n");

    srand((unsigned)time(NULL));

    int array[ARRAY_SIZE] = {1, 2, 3, 3};
    int arraySize = 4;
    
    green();

    printf("Test 1: ");

    reset();

    printf("%i ", pick(array, arraySize, 3));
    printf("%i ", pick(array, arraySize, 1));
    printf("%i ", pick(array, arraySize, 3));
    printf("| ");

    green();

    printf("Passed\n");

    reset();

    return 0;
}

int rand_between(int min, int max) 
{
    int range = max - min + 1;
    return min + (rand() % range);
}

int pick(int* arrayVar, int arraySizeVar, int targetVar)
{
    int candidates[ARRAY_SIZE];
    int candidatesSize = 0;

    for (int i = 0; i < arraySizeVar; i++) {
        if (arrayVar[i] == targetVar) {
            candidates[candidatesSize++] = i;
        }
    }

    if (candidatesSize == 0) {
        return -1;
    }

    int randomIndex = rand_between(0, candidatesSize - 1);
    return candidates[randomIndex];
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