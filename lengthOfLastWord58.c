/* Leetcode - 58. Length of Last Word (C language) - Easy */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 58. Length of Last Word (C language) - ");

    green();

    printf("Easy\n");

    char s[10][100] = {"Hello World", "   fly me   to   the moon  ","luffy is still joyboy"};
    int sizeTest[] = {11, 27, 21};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int sizeS = sizeTest[test];
        int counterChar = 0;

        for (int i = sizeS-1; i > 0; i--)
        {
            if (s[test][i] != ' ')
            {
                for (int j = i; j > 0; j--)
                {
                    if (s[test][j] != ' ')
                    {
                        counterChar++;
                    }
                    else
                    {
                        break;
                    }
                }
                break;
            }  
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", counterChar);

        green();

        printf("Passed\n");

        reset();
    }
    

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

