/* Leetcode - 49. Group Anagrams (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void printArrayOfStrings(char array[ARRAY_SIZE][ARRAY_SIZE], int arraySize);
void makeCopyOfArray(char array[ARRAY_SIZE][ARRAY_SIZE], int arraySize, char arrayCopy[ARRAY_SIZE][ARRAY_SIZE]);
void sortStringsInArray(char array[ARRAY_SIZE][ARRAY_SIZE], int arraySize);
int removeDuplicatesFromArrayOfStrings(char array[ARRAY_SIZE][ARRAY_SIZE], int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 49. Group Anagrams (C language) - Medium\n");

    char strs[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{"eat","tea","tan","ate","nat","bat"}, {""}, {"a"}};
    int strs_size[ARRAY_SIZE] = {6, 1, 1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        char output[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE];
        int output_size = 0;
        int output_index = 0;

        int sizes[ARRAY_SIZE] = {};

        char strs_copy[ARRAY_SIZE][ARRAY_SIZE] = {};
        char no_duplicates_array[ARRAY_SIZE][ARRAY_SIZE] = {};
        int no_duplicates_size = 0;

        if (strs_size[test] == 1)
        {
            strcpy(output[0][0], strs[test][0]);
            output_size = 1;
            output_index = 1;
            sizes[0] = 1;
        }
        else
        {
            
            makeCopyOfArray(strs[test], strs_size[test], strs_copy);
            makeCopyOfArray(strs[test], strs_size[test], no_duplicates_array);
            sortStringsInArray(strs_copy, strs_size[test]);
            sortStringsInArray(no_duplicates_array, strs_size[test]);

            no_duplicates_size = removeDuplicatesFromArrayOfStrings(no_duplicates_array, strs_size[test]);

            for (int i = 0; i < no_duplicates_size; i++)
            {
                for (int j = 0; j < strs_size[test]; j++)
                {
                    if (strcmp(no_duplicates_array[i], strs_copy[j]) == 0)
                    {
                        strcpy(output[output_size][output_index], strs[test][j]);
                        output_index++;
                    }
                }
                
                sizes[i] = output_index;
                output_index = 0;
                output_size++;
            }
        }
        
        green();

        printf("Test %i: ", test + 1);

        reset();

        for (int i = 0; i < output_size; i++)
        {
            printArrayOfStrings(output[i], sizes[i]);
            printf(" ");
        }
        
        printf(" | ");

        green();

        printf("Passed\n");

        reset();
    }

    return 0;
}

void printArrayOfStrings(char array[ARRAY_SIZE][ARRAY_SIZE], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]"));
    }
}

void makeCopyOfArray(char array[ARRAY_SIZE][ARRAY_SIZE], int arraySize, char arrayCopy[ARRAY_SIZE][ARRAY_SIZE])
{
    for (int i = 0; i < arraySize; i++)
    {
        strcpy(arrayCopy[i], array[i]);
    }
}

void sortStringsInArray(char array[ARRAY_SIZE][ARRAY_SIZE], int arraySize)
{
    bool flag = true;

    for (int i = 0; i < arraySize; i++)
    {
        int stringSize = strlen(array[i]);
        char str_temp[2] = "";

        while (flag)
        {
            flag = false;

            for (int j = 1; j < stringSize; j++)
            {
                if (array[i][j - 1] > array[i][j])
                {
                    str_temp[0] = array[i][j - 1];
                    array[i][j - 1] = array[i][j];
                    array[i][j] = str_temp[0];
                    
                    strcpy(str_temp, "");
                    flag = true;
                }
            }
        }

        flag = true;
    }
}

int removeDuplicatesFromArrayOfStrings(char array[ARRAY_SIZE][ARRAY_SIZE], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = i + 1; j < arraySize; j++)
        {
            if (strcmp(array[i],array[j]) == 0)
            {
                for (int k = j; k < arraySize; k++)
                {
                    strcpy(array[k], array[k + 1]);
                }
            }

            arraySize--;
        }
    }

    return arraySize + 1;
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