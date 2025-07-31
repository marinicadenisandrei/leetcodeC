/* Leetcode - 386. Lexicographical Numbers (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int* lexicalOrder(int nVar);
int getFirstDigit(int n);
void printArr(int *arr, int arrSize);

int main()
{
    yellow();

    printf("Leetcode - 386. Lexicographical Numbers (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {13,2};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int *output = lexicalOrder(n[test]);
        printArr(output, n[test]);

        free(output);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

void printArr(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), arr[i], ((i < arrSize - 1) ? ", " : "] | "));
    }
}

int getFirstDigit(int n) {
    if (n < 0) n = -n;
    while (n >= 10) {
        n /= 10;
    }
    return n;
}

int* lexicalOrder(int nVar)
{
    int *result = (int*)malloc(ARRAY_SIZE * sizeof(int));
    bool flag = true;
    int c = 0;

    for (int i = 1; i <= nVar; i++)
    {
        result[i - 1] = i;
    }

    while (flag)
    {
        flag = false;

        for (int i = 0; i < nVar - 1 - c; i++)
        {
            int first1 = getFirstDigit(result[i]);
            int first2 = getFirstDigit(result[i + 1]);

            if (first1 > first2)
            {
                int temp = result[i];
                result[i] = result[i + 1];
                result[i + 1] = temp;
                
                flag = true;
            }   
        }

        c++;
    }
        
    
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