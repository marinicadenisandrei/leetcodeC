/* Leetcode - 384. Shuffle an Array (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reset ();
void green ();
void yellow ();
void red ();

struct Solution {
    int *array;
    int arraySize;
    int *originalArray;
};

void create(struct Solution* s, int *array, int arraySize)
{
    s->array = (int*)malloc(arraySize * sizeof(int));
    s->originalArray = (int*)malloc(arraySize * sizeof(int));

    if (s->array == NULL || s->originalArray == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < arraySize; i++) {
        s->array[i] = array[i];   
        s->originalArray[i] = array[i];
    }

    s->arraySize = arraySize;
}

int* shuffle(struct Solution* s)
{
    srand(time(NULL)); 

    int *shuffled = (int*)malloc(s->arraySize * sizeof(int));
    if (shuffled == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < s->arraySize; i++) {
        shuffled[i] = s->array[i];
    }

    for (int i = s->arraySize - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        int temp = shuffled[i];
        shuffled[i] = shuffled[j];
        shuffled[j] = temp;
    }

    for (int i = 0; i < s->arraySize; i++) {
        s->array[i] = shuffled[i];
    }

    return shuffled;
}

int* resetSol(struct Solution* s)
{
    for (int i = 0; i < s->arraySize; i++) {
        s->array[i] = s->originalArray[i];
    }
    return s->array;
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++) {
        printf("%s%d%s", (i == 0) ? "[" : "", array[i], (i < arraySize - 1) ? ", " : "]\n");
    }
}

int main()
{
    yellow();

    printf("Leetcode - 384. Shuffle an Array (C language) - Medium\n");

    int inputArr[] = {1, 2, 3};
    int arraySize = 3;

    green();

    printf("Test 1: \n");

    reset();

    struct Solution solution;
    create(&solution, inputArr, arraySize);

    shuffle(&solution);
    printArray(solution.array, solution.arraySize);

    resetSol(&solution);
    printArray(solution.array, solution.arraySize);

    shuffle(&solution);
    printArray(solution.array, solution.arraySize);

    free(solution.array);
    free(solution.originalArray);

    printf("| ");

    green();

    printf("Passed\n");

    reset();

    return 0;
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