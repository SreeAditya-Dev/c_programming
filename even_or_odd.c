#include <stdio.h>

void main(){
    int arr[10];
    printf("find the even and odd number\n");

    for(int i=0;i<10;i++){
        printf("enter the number %d:",i+1);
        scanf("%d",&arr[i]);
    }
    
    int even;
    int odd;
    for (int j=0;j<10;j++){
        if ((arr[j])%2==0){
            printf("%d",arr[j]);
            even++;
        }
        else if ((arr[j])%2!=0){
            printf("%d",arr[j]);
            odd++;
        }
        else{
            printf("invalid");
        }
        
    }
    printf("total number of even :%d\n",even);
    printf(" total number of odd :%d",odd);
}