/* Leetcode - 74. Search a 2D Matrix (C language) - Medium */

#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

bool linearSearch(int array[ARRAY_SIZE], int element, int left_index, int right_index);
bool searchInMatrix(int array[ARRAY_SIZE][ARRAY_SIZE], int row_index, int row_count, int size_in, int element);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 74. Search a 2D Matrix (C language) - Medium\n");

    int matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{{1,3,5,7},{10,11,16,20},{23,30,34,60}}, {{1,3,5,7},{10,11,16,20},{23,30,34,60}}};
    int matrix_size[ARRAY_SIZE] = {3, 3};
    int matrix_in_size[ARRAY_SIZE] = {4, 4};
    int target[ARRAY_SIZE] = {3, 13};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        bool flag = searchInMatrix(matrix[test], 0, matrix_size[test] - 1, matrix_in_size[test] - 1, target[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((flag == true) ? "true" : "false"));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;   
}

bool linearSearch(int array[ARRAY_SIZE], int element, int left_index, int right_index)
{
    if (left_index > right_index)
    {
        return false;
    }
    
    if (array[left_index] == element)
    {
        return true;
    }
    else
    {
        return linearSearch(array, element, left_index + 1, right_index);
    }
}

bool searchInMatrix(int array[ARRAY_SIZE][ARRAY_SIZE], int row_index, int row_count, int size_in, int element)
{
    if (row_index >= row_count)
    {
        return false;
    }
    
    if (linearSearch(array[row_index], element, 0, size_in - 1))
    {
        return true;
    }
    else
    {
        return searchInMatrix(array, row_index + 1, row_count, size_in, element);
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
