#include <stdio.h>


void main(){
    int a;
    int b;
    int c=1;
    int s;
    printf("enter the number to print the multiplication table and how many:");
    scanf("%d %d",&a,&b);
    for (c;c<=b;c++){
        s=a*c;
        printf("%d * %d = %d\n",a,c,s);
        
    }
    
}