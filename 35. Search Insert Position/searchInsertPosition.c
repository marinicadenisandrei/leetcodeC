/* Leetcode - 35. Search Insert Position */
     
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3
#define SIZE_NUMS 4

int main(void)
{
    printf("Leetcode - 35. Search Insert Position\n");

    int nums[] = {1,3,5,6};
    int target[] = {5,2,7};

    int *ptarget =target;
    int flagFinder =false;
    
    for(int test =0;test <NUMBER_OF_TESTS;test++,ptarget++)
    {
        int *pnums =nums;

        for(int i =0;i <SIZE_NUMS;i++,pnums++)
        {
                if(*ptarget > *pnums && *ptarget <= *(pnums+1))
                {
                        printf("Test %i: %i | Passed\n",test+1,i+1);
                        i =0;
                        flagFinder =true;
                        break;
                }
        }

        if(flagFinder ==false)
        {
            printf("Test %i: %i | Passed\n",test+1,SIZE_NUMS);
        }

        flagFinder = false;
    }
}
