#include <stdio.h>

int main(void)
{
    unsigned nums[10][20] = {{3,2,2,3},{0,1,2,2,3,0,4,2}};
    unsigned sizeNums[5] = {4,8};
    unsigned target[5] = {3,2};

    for (int test = 0; test < 2; test++)
    {
    
        for (int i = 0; i < sizeNums[test]; i++)
        {
            if (nums[test][i] == target[test])
            {
                for (int j = i; j < sizeNums[test]; j++)
                {
                    nums[test][j] = nums[test][j+1];
                }
                i = 0;
                sizeNums[test]--;
            }
        }

        printf("Test %i: %i [", test+1, sizeNums[test]);
        for (int i = 0; i < sizeNums[test]; i++)
        {
            printf("%i ", nums[test][i]);
        }
        printf("] | Passed\n");
    }
}