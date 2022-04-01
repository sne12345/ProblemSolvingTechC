
#include <stdio.h>

int list [10] = {0,1,2,3,4,5,6,7,8,9};

int search_binary(int key, int low, int high){
    int middle;
    while(low <= high){
        middle = (low + high) / 2;
        if(list[middle] == key){
            return middle;
        } else if(list[middle] > key){
            return search_binary(key, low, middle - 1);
        } else {
            return search_binary(key, middle + 1, high);
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int n;
    printf("0 ~ 9 중 찾고 싶은 값을 입력 : ");
    scanf("%d", &n);
    
    int result = search_binary(n, 0, 9);
    printf("%d의 위치 = %d\n", n, result);
    
    return 0;
}
