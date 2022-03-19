#define WIDTH 10
#define HEIGHT 10

#include <stdio.h>

int screen[WIDTH][HEIGHT] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1,  0,  0, -1, -1, -1,  0, -1, -1,
    -1, -1, -1,  0,  0,  0,  0,  0, -1, -1,
    -1, -1, -1,  0, -1, -1, -1, -1, -1, -1,
    -1, -1, -1,  0,  0,  0,  0,  0, -1, -1,
    -1, -1, -1,  0, -1,  0, -1, -1, -1, -1,
    -1, -1, -1,  0, -1,  0, -1, -1, -1, -1,
    -1, -1, -1,  0, -1,  0,  0,  0, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
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
    
    if(screen[x][y] == 0){
        screen[x][y] = cnt++;
        
        cnt = flood_fill(x, y+1, cnt);
        cnt = flood_fill(x+1, y, cnt);
        cnt = flood_fill(x, y-1, cnt);
        cnt = flood_fill(x-1, y, cnt);
    }
    return cnt;
}

int main(int argc, const char * argv[]) {
    
    display(screen);
    
    printf("\n");
    
    flood_fill(4, 3, 1);
    
    display(screen);
    
    return 0;
}
