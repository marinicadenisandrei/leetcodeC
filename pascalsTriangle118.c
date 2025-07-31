#include <stdio.h>


int main(void)
{

    int numTest[10] = {5,1};
    int sizeTest = 2;
    int numRows = 0;
    

    for (int test = 0; test < 2; test++)
    {
        numRows = numTest[test];
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
        for (int i = 0; i < numRows; i++)
        {
            printf("[");
            for (int j = 0; j < sizeStarterIn; j++)
            {
                printf("%i ", starter[i][j]);
            }

            sizeStarterIn++;
            printf("]");
        }

        printf(" | Passed\n");
    }
    
   
    
    

}