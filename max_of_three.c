#include <stdio.h>
void main(){
    int a[3];
    int i ;
    int l=0;
    printf("Enter three numbers:\n");
    for (i = 0; i < 3; i++) {
        scanf("%d", &a[i]);
    }
    
    for (i = 0; i < 3; i++) {
        if (a[i]>l){
            l=a[i];
        }
    }
    printf("the largest number is:%d",l);
}