#define WIDTH 10
#define HEIGHT 10

#include <stdio.h>

int screen[WIDTH][HEIGHT] = {
    0, 0, 0,-1,-1,-1,-1,-1,-1,-1,
    -1,-1, 0,-1,-1,-1,-1,-1,-1,-1,
    -1, 0, 0, 0, 0, 0, 0,-1,-1,-1,
    -1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
    -1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
    -1,-1, 0, 0, 0,-1, 0, 0, 0,-1,
    -1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
    -1,-1,-1,-1, 0,-1, 0,-1, 0,-1,
    -1,-1,-1,-1, 0,-1,-1,-1, 0,-1,
    -1,-1,-1,-1, 0, 0, 0, 0, 0, 0
};


void display(int s[WIDTH][HEIGHT]){
    int i, j;
    for(i=0; i<WIDTH; i++){
        for(j=0; j<HEIGHT; j++){
            printf("%3d", s[i][j]);
        }
        printf("\n");
    }
}


int flood_fill(int x, int y, int cnt){
    
    if(x >= 0 && x < HEIGHT && y >= 0 && y < HEIGHT){
        if(screen[x][y] == 0){
            screen[x][y] = cnt++;
            
            cnt = flood_fill(x, y+1, cnt);
            cnt = flood_fill(x+1, y, cnt);
            cnt = flood_fill(x, y-1, cnt);
            cnt = flood_fill(x-1, y, cnt);
        }
    }
    return cnt;
}

int main(int argc, const char * argv[]) {
    
    printf("미로: \n");
    display(screen);
    
    printf("\n시작점을 <0 0>으로 한 미로방문<순서표기>:\n");
    
    flood_fill(0, 0, 1);
    
    display(screen);
    
    return 0;
}
