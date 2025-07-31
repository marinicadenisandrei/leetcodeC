/* Leetcode - 145. Binary Tree Postorder Traversal (C language) */

#include <stdio.h>
#include <math.h>
#include <stddef.h>

#define NUMBER_OF_TESTS 3

int removeNullElements (int *array, int sizeArray);
int loopDepth (int sizeArray);

void reset ();
void green ();
void yellow ();

int main(void)
{   
    yellow();
    printf("Leetcode - 145. Binary Tree Postorder Traversal (C language)\n");

    int root[20][50] = {{1,0,2,3}, {}, {1}};
    int sizeRootTest[10] = {4,0,1};

    int sizeRoot = 0;

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        sizeRoot = sizeRootTest[test];

        int power = 0;
        int start = pow(2,power);
        int depth = 0;

        int history[] = {};
        int sizeHistory = 0;

        int nullCounter = 0;

        int output[50] = {};
        output[0] = root[test][0];
        int sizeOutput = 1;

        int *pOutput = NULL;

        int loopSize = loopDepth(sizeRoot);

        for (int i = 0; i < loopSize; i++)
        {
            depth += pow(2,power);

            for (int his = 0; his < sizeHistory; his++)
            {
                nullCounter += (history[his] == 0) ? 2 : 0;
            }     

            sizeHistory = 0;

            for (int zr = 0; zr < nullCounter; zr++)
            {
                output[sizeOutput] = 0;
                sizeOutput++;
                history[sizeHistory] = 0;
                sizeHistory++;
            }

            depth -= nullCounter;

            nullCounter = 0;

            depth = (depth > sizeRoot) ? sizeRoot : depth;

            for (int j = start; j < depth; j++)
            {
                output[sizeOutput] = root[test][j];
                sizeOutput++;
                history[sizeHistory] = root[test][j];
                sizeHistory++;
            }

            start = depth;
            
            power++;

            loopSize += (i == loopSize-1 && sizeRoot-depth > 0) ? 1 : 0;
            
        }

        sizeOutput = removeNullElements(output, sizeOutput);

        pOutput = output + sizeOutput - 1;

        green();

        printf("Test %i: ", test+1);

        reset();

        printf("[ ");

        for (int i = sizeOutput; i > 0; i--, pOutput--)
        {
            printf("%i ", *pOutput);
        }
        
        printf("]");

        green();

        printf(" | Passed\n");

        reset();
    }
    
    return 0;
}

int removeNullElements(int *array, int sizeArray)
{
    int j = 0;
    for (int i = 0; i < sizeArray; i++)
    {
        if (array[i] != 0)
        {
            array[j] = array[i];
            j++;
        }
    }
    
    return j;
}

int loopDepth(int sizeArray)
{
    int powerLoop = 0;

    while(sizeArray > 0)
    {
        sizeArray -= pow(2,powerLoop);
        powerLoop++;
    }

    return powerLoop;
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
