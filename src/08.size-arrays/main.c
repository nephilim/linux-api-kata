#include <stdio.h>

int main(int argc, char* argv[])
{
    //int numbers[] = {1, 2, 3, 4, 5};
    char name[] = "nephilim";    // char name* = "nephilim";의 경우 크기가 8
    char full_name[] = {
        'D' ,'o' ,'n' ,'g' ,'w' ,'o' ,'o' ,'k' ,' ' ,'L' ,'e' ,'e' , '\0'  
    };
    char full_name_nosz[] = {
        'D' ,'o' ,'n' ,'g' ,'w' ,'o' ,'o' ,'k' ,' ' ,'L' ,'e' ,'e' 
    };

    printf("number of chars in name(%s): %ld\n", name, sizeof(name)/sizeof(char));
    printf("number of chars in full_name(%s): %ld\n", full_name, sizeof(full_name)/sizeof(char));
    printf("number of chars in full_name_nosz(%s): %ld\n", full_name_nosz, sizeof(full_name_nosz)/sizeof(char));
    return 0;
}
