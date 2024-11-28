#include <stdio.h>

int main(){
    char a[4];
    printf("enter the number:\n");
    for (int i=1;i<4;i++){
        a[i]=i;
        

    }
    
    // for (int i=1;i<4;i++){
    //     printf("%c ",a[i]);
        
    // }
    printf("%s",&a);
}