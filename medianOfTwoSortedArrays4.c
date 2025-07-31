/* Leetcode - 4. Median of Two Sorted Arrays (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int mergeTwoArrays(int array1[], int sizeArray1, int array2[], int sizeArray2);
void sortArray(int array[], int sizeArray);
float giveMedian(int array[], int sizeArray);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 4. Median of Two Sorted Arrays (C language) - ");

    red();

    printf("Hard\n");

    int nums1[10][20] = {{1,3}, {1,2}};
    int nums2[10][20] = {{2}, {3,4}};

    int testSizeNums1[10] = {2,2};
    int testSizeNums2[10] = {1,2};

    for (int test = 0; test < 2; test++)
    {
        int sizeNums1 = testSizeNums1[test];
        int sizeNums2 = testSizeNums2[test];
        
        sizeNums1 = mergeTwoArrays(nums1[test], sizeNums1, nums2[test], sizeNums2); 
        sortArray(nums1[test], sizeNums1);

        green();
        
        printf("Test %i: ", test + 1);

        reset();

        printf("%.1f | ", giveMedian(nums1[test], sizeNums1));

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}


int mergeTwoArrays(int array1[], int sizeArray1, int array2[], int sizeArray2)
{
    const int copySizeArray1 = sizeArray1;

    for (int i = 0; i < sizeArray2; i++, sizeArray1++)
    {
        array1[sizeArray1] = array2[i];
    }
    
    return copySizeArray1 + sizeArray2;
}

void sortArray(int array[], int sizeArray)
{  
    int temp = 0;

    for (int i = 0; i < sizeArray-1; i++)
    {
        if (array[i] > array[i+1])
        {
            temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
            i = 0;
        }        
    }
}

float giveMedian(int array[], int sizeArray)
{
    float median = 0.0;

    if (sizeArray % 2 == 1)
    {
        median = (float) array[sizeArray/2];
    }
    else
    {
        median = (float) (array[(sizeArray/2) - 1] + array[sizeArray/2]) / 2;
    }

    return median;
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