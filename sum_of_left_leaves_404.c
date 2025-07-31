/* Leetcode - 404. Sum of Left Leaves (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int sumOfLeftLeaves(int* rootVar, int rootSizeVar);

int main()
{
    yellow();
    
    printf("Leetcode - 404. Sum of Left Leaves (C language) - ");

    green();

    printf("Easy\n");

    int root[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1},{3,9,20,0,0,15,7}};
    int rootSize[NUMBER_OF_TESTS] = {1,7};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();
        
        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", sumOfLeftLeaves(root[test], rootSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int sumOfLeftLeaves(int* rootVar, int rootSizeVar)
{
    int sum = 0;

    for (int i = 0; i < rootSizeVar; i++)
    {
        if ((i * 2) + 1 > rootSizeVar)
        {
            break;
        }   

        sum += rootVar[(i * 2) + 1];
    }

    return sum;
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
  