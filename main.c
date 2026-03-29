#include <stdio.h>

char board[3][3];

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
char checkWinner();

int main(){

    printf("Welcome to Tic Tac Toe!!\n");

    resetBoard();
    printBoard();

    return 0;
}


void resetBoard(){

    int i, j;

    for (i=0; i<3; i++){
        for(j=0; j<3; j++){
            board[i][j]=' ';
        }
    }
}

void printBoard(){

    printf("| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("|---|---|---|\n");
    printf("| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
    printf("|---|---|---|\n");
    printf("| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);


}