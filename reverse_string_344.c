/* Leetcode - 344. Reverse String (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2
#define ARRAY_SIZE 20

void reset ();
void green ();
void yellow ();
void red ();

void reverseString(char *sVar, int sizeVar);
void printCharArray(char *array, int arraySize);

int main()
{
    yellow();

    printf("Leetcode - 344. Reverse String (C language) - ");

    green();

    printf("Easy\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {{'h','e','l','l','o'}, {'H','a','n','n','a','h'}};
    int size[NUMBER_OF_TESTS] = {5,6};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        reverseString(s[test], size[test]);
        printCharArray(s[test], size[test]);

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

void printCharArray(char *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%c%s", ((i == 0) ? "[" : " "), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

void reverseString(char *sVar, int sizeVar)
{
    for (int i = 0; i < (int)(sizeVar / 2); i++)
    {
        char temp = sVar[i];
        sVar[i] = sVar[sizeVar - 1 - i];
        sVar[sizeVar - 1 - i] = temp;
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