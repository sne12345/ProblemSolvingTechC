
#include <stdio.h>

#define X_VALUE 5
#define Y_VALUE 5

int dx [8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy [8] = {-1, 0, 1, 1, 1, 0, -1, -1};

/*
#####
#*###
##*##
#*###
###*#
 */

void readBombInfo(char grid[][Y_VALUE+1]){
    int i;
    printf("Input Grid\n");
    for(i=0; i<X_VALUE; i++){
        scanf("%s", grid[i]);
    }
}

void countBomb(char grid[][Y_VALUE+1], int numOfBombs[][Y_VALUE]){
    int i,j;
    for(i=0; i<X_VALUE; i++){
        for(j=0; j<Y_VALUE; j++){
            if(grid[i][j] == '*'){
                for(int k=0; k<8; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    
                    if(grid[nx][ny] != '*'){
                        numOfBombs[nx][ny] += 1;
                    }
                }
            }
        }
    }
}

void display_numOfBombs(char grid[][Y_VALUE+1], int numOfBombs[][Y_VALUE]){
    int i,j;
    for(i=0; i<X_VALUE; i++){
        for(j=0; j<Y_VALUE; j++){
            if(grid[i][j] == '*'){
                printf("*");
            } else {
                printf("%d", numOfBombs[i][j]);
            }
        }
        printf("\n");
    }
}


int main(int argc, const char * argv[]) {
    
    char grid[X_VALUE][Y_VALUE+1];  // 문자열의 경우 마지막에 NULL 넣어야 하므로 Y_VALUE + 1
    
    int numOfBombs[X_VALUE][Y_VALUE] = {0};
    
    readBombInfo(grid);
    countBomb(grid, numOfBombs);
    display_numOfBombs(grid, numOfBombs);
    
    return 0;
}
