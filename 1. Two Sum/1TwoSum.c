#include <stdio.h>

int main(void)
{
    int nums[][5] = {{2,7,11,15}, {3,2,4}, {3,3}};
    int size[] = {4,3,2};
    int targets[] = {9,6,6};
    int counter_test = 1;

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < size[j]; i++)
        {
            if (nums[j][i] + nums[j][i+1] == targets[j])
            {
                printf("Test %i: %i %i\n", counter_test, i, i+1);
            }
        }
        counter_test++;
    }
}