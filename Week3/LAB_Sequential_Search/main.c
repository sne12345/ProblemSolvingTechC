
#include <stdio.h>

int list [10] = {0,1,2,3,4,5,6,7,8,9};

int sorted_seq_search(int key, int low, int high){
    int i;
    for(i=low; i<=high; i++){
        if(list[i] > key) return -1;
        if(list[i] == key) return i;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int n;
    printf("0 ~ 9 중 찾고 싶은 값을 입력 : ");
    scanf("%d", &n);
    
    int result = sorted_seq_search(n, 0, 9);
    printf("%d의 위치 = %d\n", n, result);
    
    return 0;
}
