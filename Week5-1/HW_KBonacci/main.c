
#include <stdio.h>

int k_bonacci(int k, int n){
    if(n >= 1 && n <= k){
        return 1;
    }
    
    int sumValue = 0;
    for(int i=1; i<=k; i++){
        sumValue += k_bonacci(k, n-i);
    }
    return sumValue;
}

int four_bonacci(int n){
    if(n >= 1 && n <= 4){
        return 1;
    }
    
    int sumValue = 0;
    for(int i=1; i<=4; i++){
        sumValue += four_bonacci(n-i);
    }
    return sumValue;
}

int main(int argc, const char * argv[]) {
    printf("%d\n", four_bonacci(2));
    printf("%d\n", four_bonacci(6));
    printf("%d\n", k_bonacci(6,10));
    
    return 0;
}
