#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 3

char board[size][size];

void resetBoard();
void printBoard();
int checkFreeSpaces();
int checkblock(int x, int y);
void playerMove();
void computermove();
char checkWinner();

int main(){

    srand(time(0));
    

    resetBoard();
    printBoard();

    while(checkFreeSpaces()>0){
        playerMove();
        if(checkFreeSpaces()<=0) break;
        computermove();
        printBoard();   
    }
}


void resetBoard(){

    int i, j;

    for (i=0; i<size; i++){
        for(j=0; j<size; j++){
            board[i][j]=' ';
        }
    }
}

void printBoard(){

    int i, j;

    system("cls");

    printf("Welcome to Tic Tac Toe!!\n");
    printf("\n");

    for(i=0; i<size; i++){
        
        for(j=0; j<size; j++){
            printf("|---");
        }
        printf("|\n");
        
        for(j=0; j<size; j++){
            printf("| %c ", board[i][j]);
        }
        printf("|\n");

    }
    
    for(j=0; j<size; j++){
            printf("|---");
        }
        printf("|\n");

}

int checkFreeSpaces(){

    int i, j, freespaces=0;

    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            if(board[i][j]==' '){
                freespaces++;
            }
        }
    }

    return freespaces;


}

int checkblock(int x, int y){

    if (board[x][y]==' ') return 1;

    return 0;
}

void playerMove(){
     
    int x,y; 

    
    do{
        
        printf("Give the line (1-%d):", size);
        scanf("%d", &x);
        printf("Give the column (1-%d):", size);
        scanf("%d", &y);
        x=x-1;
        y=y-1;
        if(x>=size || x<0 || y<0 || y>=size || checkblock(x, y)==0){
            printf("Not a valid move.\nTry again!\n");
        }
        

    }while(x>=size || x<0 || y<0 || y>=size || checkblock(x, y)==0);

    
    board[x][y]='X';


}

void computermove(){

    int x, y;

    if(checkFreeSpaces()>0){

        do{
            x= rand() % size;
            y= rand() % size;
        }while(checkblock(x, y)==0);

        board[x][y]='O';
    }
    
    

}

char checkWinner(){

    int i, j, found;
    char move;

    for(i=0; i<size; i++){
        
        found=1;
        move=board[i][0];
        
        if(move!=' '){
            for(j=1; j<size-1; j++){
                if 
            }
        }

    }
}