#include <stdio.h>

void main(){
    int a;
    int b; 
    printf("enter two number a,b:");
    scanf("%d %d", &a, &b);
    
    a = a + b;
    b = a - b;
    a = a - b;

    printf("the two number after swap %d %d \n",a,b);
}
