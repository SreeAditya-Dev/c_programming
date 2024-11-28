#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void print(char arr[3][3]){
    // Print the board
        for (int l = 0; l < 3; l++) {
            for (int j = 0; j < 3; j++) {
                printf("%c ", arr[l][j]);
            }
            printf("\n");
        }
}

int check(char arr[3][3]);

int main() {
    char player1[20], player2[20];
    char player1_symbol[2], player2_symbol[2];
    printf("Tic-Tac-Toe game\n");
    
    char choice[2];
    do {
        // 2D array declaration for Tic-Tac-Toe
        char arr[3][3] = { {'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'} };

        // Player input and symbol
        printf("Enter the player1 name: ");
        scanf("%s", player1);
        printf("Enter the player1 symbol: ");
        scanf("%s", player1_symbol);
        printf("Enter the player2 name: ");
        scanf("%s", player2);
        printf("Enter the player2 symbol: ");
        scanf("%s", player2_symbol);
        
        // Player number
        int k = 1;
        
        // Input the array element
        for (int i = 0; i < 9; i++) { // A total of 9 moves
            int m, n;
            printf("Enter row and column (0-2) for player %d: ", (k % 2 != 0) ? 1 : 2);
            scanf("%d %d", &m, &n);
            
            // Check if the input is valid and the cell is empty
            if (m < 0 || m > 2 || n < 0 || n > 2 || arr[m][n] != '_') {
                printf("Invalid move, try again.\n");
                i--; // Repeat the iteration
                continue;
            }

            // Assign 'X' or 'O' to the array
            arr[m][n] = (k % 2 != 0) ? player1_symbol[0] : player2_symbol[0];
            
            print(arr);
            if (check(arr) == 1 && (k%2!=0)){
                printf("player1 wins....\n");
                break;
            }
            if(check(arr) == 1 && (k%2==0)){
                printf("player2 wins....\n");
                break;
            }

            k++; // Switch player

        }

        // Print the board
        printf("\n");
        print(arr);
       


        printf("Enter the choice to continue (y/Y to continue): ");
        scanf("%s", choice);
    } 
    while (strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0);

    return 0;
}

int check(char arr[3][3]){
    // check row 
    for (int i=0;i<3;i++){
        if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0]!='_'){
            return 1;
        }
    }

    // check column
    for (int i=0;i<3;i++){
        if(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i]!='_'){
            return 1;
        }
    }

    // check diagonal
    if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0]!='_'){
            return 1;
        }
    if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2]!='_'){
            return 1;
        }
    

}
