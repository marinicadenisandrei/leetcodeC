#include <stdio.h>
#include <string.h>

int main()
{
    // char strs[3][10] = {"flower", "flow", "flight"};
    char strs[3][10] = {"dog", "racecar", "car"};
    int len_strs = sizeof(strs)/ sizeof(strs[0]);
    int max = 0;
    char str[100] = "";
    // int lista[] = {};
    int lungime_str;
    
    

    for(int i = 0, check = 0; i < len_strs; i++){
        check = strlen(strs[i]);
        if(check > max){
            max = check;
        }
    }
    
    for(int j = 0; j < max; j++){
        for(int k = 0; k < len_strs; k++){
            strncat(str, &strs[k][j], 1);
        }
    }
   
    // printf("\n");
    
    lungime_str = strlen(str);
    
    // printf("%s", str);
    
    for(int q = 0; q < lungime_str; q++){
        // printf("%c\n", str[q]);
        if((str[q] == str[q+1]) && (str[q] == str[q+2])){
            printf("%c", str[q]);
        }
        
    }
    return 0;
}



