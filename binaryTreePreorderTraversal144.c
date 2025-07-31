/* Leetcode - 144. Binary Tree Preorder Traversal (C language) */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

int checkDepth(int sizeArray);
bool finderInArray(int *array, int sizeArray, int checkElement);

int main(void)
{
    printf("Leetcode - 144. Binary Tree Preorder Traversal (C language)\n");

    int root[10][10] = {{1,0,2,3}, {}, {1}};
    int size[10] = {4, 0, 1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int power = 0;
        int depth = 0;

        int* history = NULL; 

        int sizeHistory = 0;

        int finder = 0;
        int push = 0;

        int *pResult = NULL;

        int lines = checkDepth(size[test]);

        printf("Test %i: [ ", test + 1);

        for (int i = 0; i < lines; i++)
        {
            depth += pow(2,power) - push;
            
            for (int k = 0; k < sizeHistory; k++)
            {
                depth -= (history[k] == 0) ? 2 : 0;
                finder += (history[k] == 0) ? 2 : 0;            
            }

            lines += (finder > 0 && depth < size[test]) ? 1 : 0;

            sizeHistory = 0;

            history = malloc(depth * sizeof(int));

            for (int q = 0; q < finder; q++)
            {
                history[sizeHistory] = 0;
                sizeHistory += 1;
            }
            
            for (int j = pow(2,power)-1 - push; j < depth; j++)
            {
                history[sizeHistory] = root[test][j];
                sizeHistory++;
            }
            
            push = finder;
            power += 1;
            finder = 0;

            pResult = history;

            for (int i = 0; i < sizeHistory; i++, pResult++)
            {
                if (history[i] != 0 && finderInArray(root[test], size[test], history[i]) == true)
                {
                    printf("%i ", *pResult);
                }
            }
            
            free(history);
        }
        
        printf("] | Passed\n");
    }
    
    return 0;   
}

int checkDepth(int sizeArray)
{
    int numberOfLines = 0;
    int powerIncrement = 0;

    while (sizeArray > 0)
    {
        sizeArray -= pow(2,powerIncrement);
        numberOfLines++;
        powerIncrement++;
    }
    
    return numberOfLines;
}

bool finderInArray(int *array, int sizeArray, int checkElement)
{

    int flag = false;
    
    for (int i = 0; i < sizeArray; i++, array++)
    {
        if (*array == checkElement)
        {
            flag = true;
            break;
        }
    }

    return flag;
}