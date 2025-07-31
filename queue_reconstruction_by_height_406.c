/* Leetocode - 406. Queue Reconstruction by Height (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int** reconstructQueue(int peopleVar[ARRAY_SIZE][ARRAY_SIZE], int peopleSizeVar);
void sort2DArrayByFirstIndex(int arr[][ARRAY_SIZE], int arrSize);
void print2DArray(int **arr, int arrSize);
void insertIn2DArray(int **arr, int arrSize, int index, int e1, int e2);

int main()
{
    yellow();
    
    printf("Leetocode - 406. Queue Reconstruction by Height (C language) - Medium\n");

    int people[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}},{{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}}};
    int peopleSize[NUMBER_OF_TESTS] = {6,6};


    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int** ouput = reconstructQueue(people[test], peopleSize[test]);
        print2DArray(ouput, peopleSize[test]);

        green();

        printf("Passed\n");

        for (int i = 0; i < peopleSize[test]; i++)
        {
            free(ouput[i]);   
        }

        free(ouput);
    }
    
    reset();

    return 0;
}

void insertIn2DArray(int **arr, int arrSize, int index, int e1, int e2)
{
    for (int i = arrSize - 1; i >= index; i--)
    {
        arr[i + 1][0] = arr[i][0];
        arr[i + 1][1] = arr[i][1];
    }

    arr[index][0] = e1;
    arr[index][1] = e2;
}

void print2DArray(int **arr, int arrSize)
{
    printf("[");

    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), arr[i][j], ((j < 1) ? ", " : "]"));
        }      
    }

    printf("] | ");
}

void sort2DArrayByFirstIndex(int arr[][ARRAY_SIZE], int arrSize)
{
    int c = 0;
    bool flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < arrSize - 1 - c; i++)
        {
            if ((arr[i][0] < arr[i + 1][0]))
            {
                int temp = arr[i][0];
                arr[i][0] = arr[i + 1][0];
                arr[i + 1][0] = temp;

                temp = arr[i][1];
                arr[i][1] = arr[i + 1][1];
                arr[i + 1][1] = temp;

                flag = true;
            }
        }

        c++;
    }
}

int** reconstructQueue(int peopleVar[ARRAY_SIZE][ARRAY_SIZE], int peopleSizeVar)
{
    int **result = (int**)malloc(ARRAY_SIZE * sizeof(int*));
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        result[i] = (int*)malloc(2 * sizeof(int));
    }
    
    int resultSize = 0;

    sort2DArrayByFirstIndex(peopleVar, peopleSizeVar);

    for (int i = 0; i < peopleSizeVar; i++)
    {
        insertIn2DArray(result, resultSize, peopleVar[i][1], peopleVar[i][0], peopleVar[i][1]);
        resultSize++;
    }
    
    // print2DArray(result, resultSize);
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