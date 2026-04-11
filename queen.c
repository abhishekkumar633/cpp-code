#include<stdio.h>
#include<stdbool.h>
#define N 4
int board[N];

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||                        // Same column
            board[i] - i == col - row ||              // Same major diagonal
            board[i] + i == col + row) {              // Same minor diagonal
            return false;
        }
    }
    return true;
}

bool solve_N_queen(int row){
    if(row==N){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i]==j)
                 printf("Q");
                    else
                        printf(".");
            }
                printf("\n");
        }
            printf("\n");
    }

    for(int col=0;col<N;col++){
        if(isSafe(row,col)){
            board[row]=col;
            if(solve_N_queen(row + 1))
              return true;
        }
    }
    return false;
}
int main(){
     if (!solve_N_queen(0)) {
        printf("No solution exists.\n");
    }
    return 0;

}