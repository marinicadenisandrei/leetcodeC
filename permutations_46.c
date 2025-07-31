
/* Leetcode - 46. Permutations (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 3
#define ARRAY_SIZE 20

void printArray(int array[ARRAY_SIZE], int sizeArray);
int generateNumberOfPermutations(int sizeArray);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 46. Permutations (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3}, {0,1}, {1}};
    int size_nums[ARRAY_SIZE] = {3, 2, 1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int depth = generateNumberOfPermutations(size_nums[test]);
        int index1 = 0;
        int index2 = 1;
        int temp = 0;

        green();

        printf("Test %i: ", test + 1);

        reset();

        printArray(nums[test], size_nums[test]);
        printf(", ");

        while (depth > 1)
        {
            
            if (index2 == size_nums[test])
            {
                temp = nums[test][0];
                nums[test][0] = nums[test][size_nums[test] - 1];
                nums[test][size_nums[test] - 1] = temp;

                printArray(nums[test], size_nums[test]);
                printf(", ");

                index1 = 0;
                index2 = 1;
            }
            else
            {
                temp = nums[test][index1];
                nums[test][index1] = nums[test][index2];
                nums[test][index2] = temp;

                printArray(nums[test], size_nums[test]);
                printf(", ");
                index1++;
                index2++;
            }
        
            depth--;
        }

        printf("| ");

        green();

        printf("Passed\n");

        reset();
    }

    return 0;
}

void printArray(int array[ARRAY_SIZE], int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
    {
        printf("%s%i%s", (i == 0) ? "[" : "", array[i], (i < sizeArray - 1) ? ", " : "]");
    }
}

int generateNumberOfPermutations(int sizeArray)
{
    int depth = 1;

    for (int i = 1; i <= sizeArray; i++)
    {
        depth *= i;
    }
    
    return depth;
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