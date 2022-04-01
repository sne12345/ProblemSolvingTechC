
#include <stdio.h>

char arr [] = {'A', 'B', 'C', 'D', 'E', 'F','G'};

void comb(int n, int* bucket, int bucketSize, int k){
    if(k == 0){
        for(int i=0; i<bucketSize; i++){
            printf("%c ", arr[bucket[i]]);
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
    
    int bucket [3];
    comb(7, bucket, 3, 3);
    
    return 0;
}
