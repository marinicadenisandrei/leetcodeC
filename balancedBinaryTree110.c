#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binarySamplingNo(int size);
int removeNull(int *list, int size);

int main(void)
{

    int root[20][20] = {{3,9,20,0,0,15,7},{1,2,2,3,3,0,0,4,4}};
    int rootSizeTest[5] = {7,9};
    int sizeTests = 2;
    int counterTest = 1;

    for (int test = 0; test < sizeTests; test++)
    {   
        int rootSize = rootSizeTest[test];
        int sampling = binarySamplingNo(rootSize);

        int left[20] = {};
        int right[20] = {};

        int counterLeft = 0;
        int counterRight = 0;

        int power = 1;
        int depth = 0;
        
        rootSize--;
        
        for (int i = 1; i < sampling; i++)
        {
            depth += pow(2,power);
    
            if (pow(2,power) < rootSize)
            {
                for (int j = depth-pow(2,power)+1; j <= depth-(pow(2,power)/2); j++)
                {
                    left[counterLeft] = root[test][j];
                    counterLeft++;
                }

                for (int k = depth-(pow(2,power)/2)+1; k <= depth; k++)
                {
                    right[counterRight] = root[test][k];
                    counterRight++;
                }
            }
            else
            {
                if (pow(2,power)-rootSize < pow(2,power)/2)
                {
                    for (int l = depth-pow(2,power)+1; l <= depth-(pow(2,power)/2)-rootSize-2; l++)
                    {
                        left[counterLeft] = root[test][l];
                        counterLeft++;
                    }
                    
                }
                else
                {
                    for (int l = depth-pow(2,power)+1; l <= depth-(pow(2,power)/2); l++)
                    {
                        left[counterLeft] = root[test][l];
                        counterLeft++;
                    }
                    
                    rootSize -= pow(2,power)/2;

                    for (int m = depth-pow(2,power)+1+(pow(2,power)/2); m <= depth-(pow(2,power)/2)-rootSize; m++)
                    {   
                        right[counterRight] = root[test][m];
                        counterRight++;
                    }
                }
                
            }
            
            power++; 
            rootSize -= depth;  
        }
        
        counterLeft = removeNull(left, counterLeft);
        counterRight = removeNull(right, counterRight);

        printf("Test %i: %s | Passed\n", counterTest, (abs(binarySamplingNo(counterLeft) - binarySamplingNo(counterRight)) <= 1) ? "True" : "False");

        counterTest++;
    }
    
}

int binarySamplingNo(int size)
{
    int power = 0;
    int samplingNo = 0;

    while (size > 0)
    {
        size -= pow(2,power);
        power++;
        samplingNo++;
    }

    return samplingNo;
}

int removeNull(int *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i] == 0)
        {
            for (int j = i; j < size; j++)
            {
                list[j] = list[j+1];
                size--;
            }
            i=0;
        }
    }
    
    return size;
}

