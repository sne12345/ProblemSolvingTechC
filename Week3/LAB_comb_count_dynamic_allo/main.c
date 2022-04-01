
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int m, int picked[], int toPick){
    int smallest, lastIndex;
    if(toPick == 0){
        for(int i=0; i<m; i++){
            printf("%d ", picked[i]);
        }
        printf("\n");
        return;
    }
    
    lastIndex = m - toPick - 1;
    
    if(m == toPick){
        smallest = 0;
    } else {
        smallest = picked[lastIndex] + 1;
    }
    
    for(int i=smallest; i<n; i++){
        picked[lastIndex + 1] = i;
        pick(n, m, picked, toPick - 1);
    }
}

int main(int argc, const char * argv[]) {

    int n, m;
    
    printf("Enter n and m:");
    scanf("%d %d", &n, &m);
    
    int *picked = (int *)malloc(sizeof(int) * m);
    
    pick(n, m, picked, m);
    
    return 0;
}
