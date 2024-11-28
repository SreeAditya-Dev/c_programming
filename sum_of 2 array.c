# include <stdio.h>

void main(){
    int arr1[5];
    int arr2[5];
    int arr3[5];
    printf("calculate the sum of two array\n");
    for (int i=0;i<5;i++){
        printf("enter the arr1 element %d:",i+1);
        scanf("%d",&arr1[i]);
    }
    printf("\n");
    for (int i=0;i<5;i++){
        printf("enter the arr1 element %d:",i+1);
        scanf("%d",&arr2[i]);
    }

    for (int i=0;i<5;i++){
        arr3[i]=arr1[i]+arr2[i];
        
    }
    
    for (int i=0;i<5;i++){
        printf("%d\n",arr3[i]);
    }
}