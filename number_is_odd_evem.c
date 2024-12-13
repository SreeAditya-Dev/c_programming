#include <stdio.h>

void main(){
    long int a;
    printf("enter the number");
    scanf("%ld",&a);
    
    if (a%2==0){
        printf("the given number %ld is even\n",a);
    }
    else{
        printf("he given number %ld is odd\n",a);
    }

}