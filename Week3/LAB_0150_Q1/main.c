#include <stdio.h>

int answer(int a, int b, int up){
    if(a <= 0 && b <= 0){
        return 0;
    }

    int result = a % 10 + b % 10 + up;
    if(result >= 10){
        return answer(a / 10, b / 10, result / 10) + 1;
    } else {
        return answer(a / 10, b / 10, 0);
    }
}
int main(void) {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    printf("%d", answer(a, b, 0));
    return 0;
}
