#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int resultSize = 0;

char** binaryTreePaths(int *rootVar, int rootVarSize);
void printStringArray(char **stringArray, int stringArraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();
    
    printf("Leetcode - 257. Binary Tree Paths (C language) - ");

    green();

    printf("Easy\n");

    int root[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3,0,5},{1}};
    int rootSize[NUMBER_OF_TESTS] = {5,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);
        
        reset();

        char **output = binaryTreePaths(root[test], rootSize[test]);
        printStringArray(output, resultSize);

        for (int i = 0; i < ARRAY_SIZE; ++i) 
        {
            free(output[i]);
        }

        free(output);
        resultSize = 0;

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

void printStringArray(char **stringArray, int stringArraySize)
{
    for (int i = 0; i < stringArraySize; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""), stringArray[0], ((i < stringArraySize - 1) ? ", " : "] | "));
    }
}

char** binaryTreePaths(int *rootVar, int rootVarSize)
{
    char **result = (char **)malloc(ARRAY_SIZE * sizeof(char *));
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        result[i] = (char *)malloc((strlen(result[i]) + 1) * sizeof(char));
    }

    if (rootVarSize == 1)
    {
        char temp[5];
        strcpy(result[resultSize], "");
        sprintf(temp, "%d", rootVar[0]);
        strcat(result[resultSize++], temp);
        
        return result;
    }
    
    int stop = 4;
    int index = 0;
    int counter = 0;

    int pathFormation[ARRAY_SIZE][ARRAY_SIZE] = {};
    int pathFormationInSize[ARRAY_SIZE] = {0};
    int pathFormationSize = 0;

    int depth = 1;
    int c = 0;;

    while (depth < rootVarSize)
    {
        depth *= 2;
        c++;
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < depth / 2; j++)
        {
            if (counter == stop)
            {
                index++;
                counter = 0;
            }

            pathFormation[pathFormationSize][pathFormationInSize[pathFormationSize]++] = index;
            counter++;
        }

        index++;
        stop /= 2;
        counter = 0;
        pathFormationSize++;
    }

    for (int i = 0; i < pathFormationInSize[0]; i++) 
    {
        strcpy(result[resultSize], "");

        for (int j = 0; j < pathFormationSize; j++) 
        {
            char temp[5];
            sprintf(temp, "%d", rootVar[pathFormation[j][i]]);
            strcat(result[resultSize], temp);

            if (j < pathFormationSize - 1) 
            {
                strcat(result[resultSize], "->");
            }
        }

        resultSize++;
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