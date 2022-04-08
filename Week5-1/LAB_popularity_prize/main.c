

#include <stdio.h>
#include <stdlib.h>

char* celebrities [5] = {"공유", "김수현", "송중기","지성","현빈"};

void comb(int n, int* bucket, int bucketSize, int k){
    if(k == 0){
        for(int i=0; i<bucketSize; i++){
            printf("%10s", celebrities[bucket[i]]);
        }
        printf("\n");
        return;
    }
    
    int lastIndex = bucketSize - k - 1;
    int smallest;
    if(k == bucketSize){
        smallest = 0;
    } else {
        smallest = bucket[lastIndex] + 1;
    }
    
    for(int item=smallest; item<n; item++){
        bucket[lastIndex + 1] = item;
        comb(n, bucket, bucketSize, k-1);
    }
}

int main(int argc, const char * argv[]) {
    
    int pick;
    printf("인기상 몇명? ");
    scanf("%d", &pick);
    
    int *bucket = (int *)malloc(sizeof(int) * pick);
    comb(5, bucket, pick, pick);
    
    return 0;
}
