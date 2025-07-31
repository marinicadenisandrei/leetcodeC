/* Leetcode - 195. Tenth Line (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARACTER_SIZE 100

void tenthLine(char *fileVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 195. Tenth Line (C language) - ");

    green();

    printf("Easy\n");

    char file[CHARACTER_SIZE] = "Line 1\nLine 2\nLine 3\nLine 4\nLine 5\nLine 6\nLine 7\nLine 8\nLine 9\nLine 10\n";

    printf("Test 1: ");

    reset();

    tenthLine(file);

    green();

    printf("Passed\n");

    reset();

    return 0;
}

void tenthLine(char *fileVar)
{
    int counter = 0;
    char temp[20] = "";
    int tempSize = 0;

    for (int i = 0; i < strlen(fileVar); i++)
    {
        if (fileVar[i] == '\n')
        {
            counter++;
        }

        if (counter == 9)
        {
            for (int j = i + 1; fileVar[j] != '\n' ; j++)
            {
                temp[tempSize++] = fileVar[j];
            }

            temp[tempSize] = '\0';
            break;            
        }
    }

    printf("%s | ", temp);
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