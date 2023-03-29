#include <stdio.h>

int main()
{
    
    int nums[] = {0,0,1,1,1,2,2,3,3,4,5,5,5,5,5,5};
    int len_nums = sizeof(nums)/sizeof(nums[0]);
    int expected_nums[] = {};
    int counter = 0;
    int flag = 0;
    
    for(int i = 0 ; i < len_nums; i++){
        for(int j = 0; j < counter; j ++){
            if(nums[i] != nums[j]){
                flag = 0;
            }
            else{
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            expected_nums[counter] = nums[i];
            counter++;
        }
    }
     
    for(int k = 0; k < counter; k++){
        printf("%i", expected_nums[k]);
    }

    return 0;
}

