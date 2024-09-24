#include <stdio.h>
void main(){
    int a,c,s ;
    int b = 0 ; 
    int d = a ;
    printf("check whether the number is amstrong number or not...");
    printf("enter the number;");
    scanf("%d",&a);
    
    while(d>0){
        c=d%10;
        s=s+(c*c*c);
        d=d/10;
    }

    if (s==a){
        printf("it is amstrong number");
    }
    else{
        printf("not amstrong number");
    }
    

}