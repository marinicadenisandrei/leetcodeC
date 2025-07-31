#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define NULLVAR 999

void removNullElements(int *list, int len);

int main(void)
{
    // Test 1
    int nums[10] = {-10, -3, 0, 5, 9};
    int sizeNums = 5;

    // Test 2
    // int nums[10] = {1,3};
    // int sizeNums = 2;

    if (sizeNums % 2 == 0)
    {   
        int temp = nums[sizeNums/2];
        nums[sizeNums/2] = NULLVAR;
        nums[sizeNums/2+1] = temp;
        sizeNums++;

        if (sizeNums > 3)
        {
             for (int i = (sizeNums/2)+1; i < sizeNums; i++)
            {
                nums[i] = nums[i+1];
            }
        }
    }
    
    int copySizeNums = sizeNums;

    int half = (int) sizeNums/2;
    int power = 1;

    int output[50] = {};
    int sizeOutput = 0;

    int i = 1;

    output[sizeOutput] = nums[half];
    sizeOutput++;
    sizeNums--;

    while (sizeNums > 0)
    {
        if (sizeNums-pow(2,power) >= 0)
        {
            for (i = 1; i < pow(2,power); i++)
            {
                output[sizeOutput] = nums[half-i];
                sizeOutput++;

                output[sizeOutput] = nums[copySizeNums-i];
                sizeOutput++;
            }
        }
        else
        {
            for (int j = 1; j < pow(2,power)-sizeNums; j++)
            {
                output[sizeOutput] = nums[half-i];
                sizeOutput++;

                output[sizeOutput] = NULLVAR;
                sizeOutput++;

                output[sizeOutput] = nums[copySizeNums-i];
                sizeOutput++;

                output[sizeOutput] = NULLVAR;
                sizeOutput++;
            }
            
        }

        sizeNums -= pow(2,power);
        power++;
    }
    
    removNullElements(output, sizeOutput);

    return 0;
}


void removNullElements(int *list, int len)
{
    int i = 0;
    int size = len;
   

    while (list[i] == 999)
    {
        size--; 

        for (int j = i; j < size; j++)
        {
            list[j] = list[j+1];
        }
        
    }
    

    while (list[size-1] == 999)
    {
        size--;
    }


    for (int i = 0; i < size; i++)
    {
        printf("%i ", list[i]);
    }
}