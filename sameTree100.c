#include <stdio.h>

#define LEN_LISTS 3

int main(){

    int p[][LEN_LISTS] = {{1,2,3}, {1,2}, {1,2,1}};
    int q[][LEN_LISTS] = {{1,2,3}, {1,0,2}, {1,1,2}};

    int flag = 1;

    int counter_test = 1;

    for (int i = 0; i < LEN_LISTS; i++)
    {
        for (int j = 0; j < LEN_LISTS; j++)
        {
            if (p[i][j] != q[i][j])
            {
                flag = 0;
                break;
            }
            
        }
        
        printf("Test %i: %s\n", counter_test, ((flag == 1) ? "True": "False"));

        counter_test++;
    }
}