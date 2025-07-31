/* Leetcode - 331. Verify Preorder Serialization of a Binary Tree (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 30
#define NUMBER_OF_TESTS 3

bool isValidSerialization(char *preorderVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 331. Verify Preorder Serialization of a Binary Tree (C language) - Medium\n");

    char preorder[NUMBER_OF_TESTS][ARRAY_SIZE] = {"9,3,4,#,#,1,#,#,2,#,6,#,#","1,#","9,#,#,1"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((isValidSerialization(preorder[test]) == 1) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

bool isValidSerialization(char *preorderVar)
{ 
    bool flag = true;
    int arrayInt[ARRAY_SIZE] = {};
    int arrayIntSize = 0;

    for (int i = 0; i < strlen(preorderVar); i += 2)
    {
        if (preorderVar[i] == '#')
        {
            arrayInt[arrayIntSize++] = 0;
        }
        else
        {
            arrayInt[arrayIntSize++] = preorderVar[i] - '0';
        }
    }

    int initialSize = arrayIntSize;
    int cache = 0;
    int c = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < arrayIntSize; i++)
        {
            if (arrayInt[i] == 0)
            {
                int start = 0;
                int skip = 0;

                if ((i + 1) >= arrayIntSize)
                {
                    return false;
                }

                if ((i - 1) == 0)
                {
                    return false;
                }
                
                if (cache == 0)
                {
                    cache = 1;
                    start = i - 1;
                    skip = 3;
                }
                else
                {
                    cache = 0;
                    start = i - 2;
                    skip = 4;
                }

                int temp[ARRAY_SIZE] = {};
                int tempSize = 0;

                for (int j = 0; j < arrayIntSize; j++)
                {
                    if (j == start)
                    {
                        j += skip;
                    }

                    temp[tempSize++] = arrayInt[j];
                }

                for (int j = 0; j < tempSize; j++)
                {
                    arrayInt[j] = temp[j];
                }

                arrayIntSize = tempSize;
                tempSize = 0;

                flag = true;

                break;
            }

            if (flag)
            {
                break;
            }
        }

        c++;

        if (arrayIntSize == 3 && initialSize > arrayIntSize)
        {
            return true;
        }
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