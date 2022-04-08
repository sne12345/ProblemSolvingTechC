

#include <stdio.h>
#include <stdlib.h>

int priceList [3] = {1000, 5000, 10000};

void comb(int total, int* bucket, int picked, int sumValue, int lastIdx){
    if(sumValue == total){
        for(int i=0; i<picked; i++){
            printf("%d ", bucket[i]);
        }
        printf("\n");
        return;
    } else if(sumValue > total){
        return;
    }
    
    for(int i=lastIdx; i<3; i++){
        bucket[picked] = priceList[i];
        comb(total, bucket, picked+1, sumValue + priceList[i], i);
    }
}

int main(int argc, const char * argv[]) {
    
    int total;
    scanf("%d", &total);
    
    int maxCnt = total / 1000;
    int* bucket = (int *)malloc(sizeof(int) * maxCnt);
    
    comb(total, bucket, 0, 0, 0);
    
    return 0;
}
