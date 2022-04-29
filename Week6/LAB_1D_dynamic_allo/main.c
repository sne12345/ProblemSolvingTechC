
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    int* arr = (int *)malloc(sizeof(int) * n);
    
    for(int i=0; i<n; i++){
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    
    return 0;
}
