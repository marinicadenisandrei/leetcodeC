/* Leetcode - 136. Single Number */

#include <stdio.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

int main(void)
{

    printf("Leetcode - 136. Single Number\n");

    int nums[10][20] = {{2,2,1},{4,1,2,1,2}, {1}};
    int sizeNumsTest[10] = {3,5,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int *pnums = nums[test];
        int sizeNums = sizeNumsTest[test];
        int flag = false;
        int singleNumber;

        for (int i = 0; i < sizeNums; i++, pnums++)
        {
            
            for (int j = 0; j < sizeNums; j++)
            {   
                if (i != j)
                {
                    flag = (*pnums == nums[test][j]) ? true : flag;   
                    // printf("i = %i j = %i\n", *pnums, nums[test][j]);
                }
            }

            singleNumber = (flag == false) ? *pnums : singleNumber;
            flag = false;
        }
        
        printf("Test %i: %i | Passed\n", test+1, singleNumber);
    }
}