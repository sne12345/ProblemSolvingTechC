

#include <stdio.h>
#include <stdlib.h>

int formulaList [] = {+1, -1};

void perm(int formula, int* bucket, int bucketSize, int picked, int* numberList){
    if(picked == bucketSize){
        int sumValue = 0;
        for(int i=0; i<bucketSize; i++){
            if(bucket[i] > 0){
                printf("+");
            }
            printf("%d", bucket[i]);
            sumValue += bucket[i];
        }
        printf(" = %d\n", sumValue);
        return;
    }
    
    for(int i=0; i<formula; i++){
        bucket[picked] = numberList[picked] * formulaList[i];
        perm(formula, bucket, bucketSize, picked+1, numberList);
    }
}

int main(int argc, const char * argv[]) {
    
    int n;
    scanf("%d", &n);
    
    int* numberList = (int *)malloc(sizeof(int) * n);
    int* bucket = (int *)malloc(sizeof(int) * n);
    for(int i=1; i<=n; i++){
        numberList[i-1] = i;
    }
    
    perm(2, bucket, n, 0, numberList);
    
    

    return 0;
}
