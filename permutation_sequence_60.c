#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 30
#define NUMBER_OF_TESTS 3

void printArrayOfInt(int array[ARRAY_SIZE], int arraySize);
int numberOfPermutations(int numberVar);
void bubble_sort(int array[ARRAY_SIZE], int size_array);
void populateChar(char char_var[ARRAY_SIZE], int n);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 60. Permutation Sequence (C language) - ");

    red();

    printf("Hard\n");

    int nTest[ARRAY_SIZE] = {3,4,3};
    int kTest[ARRAY_SIZE] = {3,9,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int n = nTest[test];
        int k = kTest[test];

        int permutations_number = numberOfPermutations(n);

        char permutationString[ARRAY_SIZE] = "";
        populateChar(permutationString, n);
        
        int temp = 0;
        int index1 = 0;
        int index2 = 1;

        int permutationList[ARRAY_SIZE] = {};
        int size_permutationList = 0;

        permutationList[size_permutationList] = atoi(permutationString);
        size_permutationList++;
        

        for (int i = 0; i < permutations_number - 1; i++)
        {
            if (index2 < n)
            {
                temp = permutationString[index1];
                permutationString[index1] = permutationString[index2];
                permutationString[index2] = temp;

                permutationList[size_permutationList] = atoi(permutationString);
                size_permutationList++;
            }
            else
            {
                temp = permutationString[0];
                permutationString[0] = permutationString[n - 1];
                permutationString[n - 1] = temp;

                permutationList[size_permutationList] = atoi(permutationString);
                size_permutationList++;

                index1 = -1;
                index2 = 0;
            }
            
            index1++;
            index2++;
        }

        bubble_sort(permutationList, size_permutationList);
        
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("\"%i\" | ", permutationList[k]);

        green();

        printf("Passed\n");

        reset();
    }
  
    return 0;
}

void printArrayOfInt(int array[ARRAY_SIZE], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]\n"));
    }
    
}

int numberOfPermutations(int numberVar)
{
    int result = 1;

    for (int i = 1; i <= numberVar; i++) result *= i;

    return result;
}

void bubble_sort(int array[ARRAY_SIZE], int size_array)
{
    bool swapped = true;
    int factor = 0;

    while (swapped)
    {
        swapped = false;

        for (int i = 0; i < size_array - factor; i++)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                swapped = true;
            }
        }

        factor++;
    }
}

void populateChar(char char_var[ARRAY_SIZE], int n)
{
    for (int i = 1; i <= n; i++)
    {
        char str[2];
        sprintf(str,"%d",i);
        strcat(char_var,str);
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