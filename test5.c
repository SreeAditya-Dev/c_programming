#include <stdio.h>

int main(int argc,char* argv[]){
    printf("program name is : %s",argv[0]);
    
    if (argc == 1){
        printf("\nNO extra command line argument passed");
    }

    if (argc >=2){
        printf("\nNumber of arguments passed: %d",argc);
    }

    return 0;
}