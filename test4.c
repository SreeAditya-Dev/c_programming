# include <stdio.h>

int main(){
    char num[2][2] = {{'1','2'},{'3','4'}};
    char*ptr = num;
    printf("address stored in : %p\n", (void*)ptr);
    printf("value stored in prt (dereferenced): %c %s\n",*(ptr++),num[1]); // is you need to access the multi dimes array you can use %s instead of %c with single access value
    printf("value stored in prt (dereferenced): %c %s\n",*(++ptr),num[0]);
    for (int i =0;i<4;i++){
        printf("%c\t",num[i][i]); // but in this case it is not 
    }
    printf("\n");
    for (int i =0;i<4;i++){
        printf("%c\t",*(ptr++)); // using the pointer you can access the multi dim array using single for loop
    }
    printf("\n");

    for (int i =0;i<4;i++){
        printf("%s\n",num[i]); // i first it self we can assess it
    }



    return 0;
}