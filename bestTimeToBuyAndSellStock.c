/* Leetcode 121. Best Time to Buy and Sell Stock */

#include <stdio.h>
#include <stddef.h>

int removeLoseDay(int *list, int size);

int main(void)
{
    printf("Leetcode 121. Best Time to Buy and Sell Stock\n");

    int prices[20][50] = {{7,1,5,3,6,4},{7,6,4,3,1}};
    int testSizePrices[5] = {6,5} ;

    for (int test = 0; test < 2; test++)
    {   
        int sizePrices = testSizePrices[test];
        sizePrices = removeLoseDay(prices[test], sizePrices);

        if (sizePrices < 2)
        {
            printf("Test %i: %i | Passed\n", test+1, 0);
        }
        else
        {
            int bestProfit = 0;
            int *pival = NULL;
            int *pjval = NULL;

            for (int i = 0; i < sizePrices; i++)
            {
                for (int j = 0; j < sizePrices; j++)
                {
                    if (prices[test][i]-prices[test][j] > bestProfit)
                    {
                        pival = &prices[test][i];
                        pjval =  &prices[test][j];
                        bestProfit = prices[test][i]-prices[test][j];
                    }
                }
            }

            printf("Test %i: %i | Passed\n", test+1, bestProfit);
        }
    }
}

int removeLoseDay(int *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        i = 0;
        if (list[i] > list[i+1])
        {
            for (int j = 0; j < size; j++)
            {
                list[j] = list[j+1];
            }
            size--;
        }
        else
        {
            break;
        }
    }
    return size;
}
