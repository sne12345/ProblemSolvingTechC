
#include <stdio.h>
#include <stdlib.h>

char *celebrities [5] = {"공유", "김수현", "송중기", "지성", "현빈"};
void perm(int n, int* bucket, int bucketSize, int toPick){
    if(toPick == 0){
        for(int i=0; i<bucketSize; i++){
            printf("%10s", celebrities[bucket[i]]);
        }
        printf("\n");
        return;
    }
    
    int lastIdx = bucketSize - toPick - 1;
    
    for(int item=0; item<n; item++){
        int isBefore = 0;
        for(int before=0; before<=lastIdx; before++){
            if(bucket[before] == item){
                isBefore = 1;
                break;
            }
        }
        if(isBefore == 0){
            bucket[lastIdx + 1] = item;
            perm(n, bucket, bucketSize, toPick-1);
        }
    }
}
int main(int argc, const char * argv[]) {
    int pick;
    printf("상의 종류는? ");
    scanf("%d", &pick);
    
    for(int i=0; i<pick; i++){
        printf("%9s%d", "상", i+1);
    }
    printf("\n");
    int* bucket = (int *)malloc(sizeof(int) * pick);
    perm(5, bucket, pick, pick);
    
    return 0;
}
