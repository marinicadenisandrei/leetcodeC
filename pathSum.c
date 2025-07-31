#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int binaryDepth(int size);
int startingBinary(int *list, int binarySize);

int main(void)
{

    int root[50][50] = {{5,4,8,11,0,13,4,7,2,0,0,0,1},{1,2,3}};
    int testSizes[10] = {13,3};
    int targetTest[10] = {22,5};
    int counterTest = 1;

    for (int test = 0; test < 2; test++)
    {
        int rootSize = testSizes[test];
        int target = targetTest[test];
        int power = 0;
        int counter = 0;
        int sum = 0;

        int start[10] = {};
        int flagNegative = false;
        int flagFinder = false;

        startingBinary(start, binaryDepth(rootSize));

        for (int i = 0; i < binaryDepth(rootSize)/2; i++)
        {
            for (int j = 0; j < binaryDepth(rootSize); j++)
            {
                for (int k= 0; k < binaryDepth(rootSize); k++)
                {   
                    sum += (root[test][start[k]] != 0) ? root[test][start[k]] : (flagNegative = true, 0);
                }

                (flagFinder = (sum == target) ? true : false);
                if(flagFinder) break;

                start[3] += 1;
                counter++;
                sum = 0;
                
                if (counter == 2)
                {
                    start[2] += 1;
                    counter = 0;
                }

                counter == 2 ? (start[2] += 1, counter = 0) : 0;
            }

            if (flagFinder == true)
            {
                break;
            }
    
            start[1] += 1;
            flagNegative == true ? (start[3] -= 2, flagNegative = false) : 0; 
        }

        printf("Test %i: %s | Passed\n", counterTest, (flagFinder == true) ? "True" : "False");
        counterTest++;
    }
}

int binaryDepth(int size)
{

    int power = 0;
    int counter = 0;

    while (size > 0)
    {
        size -= pow(2,power);
        counter++;
        power++;
    }

    return counter;
}

int startingBinary(int *list, int binarySize)
{   
    int power = 0;
    int element = 0;

    for (int i = 0; i < binarySize; i++)
    {
        
        list[i] = element;
        element += pow(2,power);
        power++;
    }
}