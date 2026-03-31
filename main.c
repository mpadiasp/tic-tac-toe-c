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

    char winner=' ';

    resetBoard();
    printBoard();

    while(checkFreeSpaces()>0 && winner==' '){
        
        playerMove();
        winner=checkWinner();

        if(winner!=' ' || checkFreeSpaces()<=0) break;
        computermove();
        printBoard();
        winner=checkWinner();  
    }

    printf("\n");
    
    if(winner=='X'){
        printf("Congrats!\nYou won!!\n");
    }
    else if(winner=='O'){
        printf("You lost!\n");
    }
    else{
        printf("It's a Draw!\n");
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

    int i, j;
    char current;

    for(i=0; i<size; i++){
        for(j=0; j<size; j++){

            current=board[i][j];

            if(current!=' '){

                if(j+2<size){
                    
                    if(board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2]){
                        return current;
                    }

                }
                
                if(i+2<size){
                    
                    if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j]){
                        return current;
                    }

                }

                if(i+2<size && j+2<size){

                    if(board[i][j]==board[i+1][j+1] && board[i][j]==board[i+2][j+2]){
                        return current;
                    }

                }

                if(i+2<size && j-2>=0){

                    if(board[i][j]==board[i+1][j-1] && board[i][j]==board[i+2][j-2]){
                        return current;
                    }

                }


            }

        }
    }

    return ' ';  
}