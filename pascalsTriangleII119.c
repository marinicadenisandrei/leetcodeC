#include <stdio.h>


int main(void)
{
    int numTest[10] = {3,0,1};
    int sizeTest = 3;
    int numRows = 0;

    for (int test = 0; test < sizeTest; test++)
    {
        numRows = numTest[test]+1;
        int starter[50][50] = {{1},{1,1}};
        int sizeStarterOut = 1;
        int sizeStarterIn = 0;
        int last = 2;

        for (int i = 2; i < numRows; i++)
        {
            starter[sizeStarterOut+1][sizeStarterIn] = 1;
            sizeStarterIn++;
            
            for (int j = 0; j < last; j++)
            {
                starter[sizeStarterOut+1][sizeStarterIn] = starter[sizeStarterOut][j]+starter[sizeStarterOut][j+1];
                sizeStarterIn++;
            }

            starter[sizeStarterOut+1][sizeStarterIn-1] = 1;

            sizeStarterIn = 0;
            sizeStarterOut++;
            last++;
        }

        sizeStarterIn = 1;

        printf("Test %i: ", test+1);
        for (int i = numRows-1; i < numRows; i++)
        {
            printf("[");
            for (int j = 0; j < numRows; j++)
            {
                printf("%i ", starter[i][j]);
            }

            sizeStarterIn++;
            printf("] ");
        }

        printf(" | Passed\n");
    }
}