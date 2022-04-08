

#include <stdio.h>
#include <stdlib.h>

void perm(int notation, int* bucket, int bucketSize, int picked){
    if(picked == bucketSize){
        for(int i=0; i<bucketSize; i++){
            printf("%d", bucket[i]);
        }
        printf("\n");
        return;
    }
    
    for(int item=0; item<notation; item++){
        bucket[picked] = item;
        perm(notation, bucket, bucketSize, picked+1);
    }
        
}

int main(int argc, const char * argv[]) {
    
    int pick;
    scanf("%d", &pick);
    int* bucket = (int *)malloc(sizeof(int) * pick);
    
    perm(4, bucket, pick, 0);
    
    return 0;
}
