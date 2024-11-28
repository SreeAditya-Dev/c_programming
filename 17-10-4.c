#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

int main(int argc, char *argv[]) {

        if (argc != 2){

        printf("Usage: %s <inout files>\n", argv[0]);

        return 1;
        }



FILE *file = fopen(argv[1], (file) );
   perror("Error file"); 
   return 1;
}
