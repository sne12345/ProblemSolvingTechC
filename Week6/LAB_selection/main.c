
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int* arr, int arr_size){
    for(int i=arr_size-1; i>=0; i--){
        int maxInt = arr[0];
        int maxIdx = 0;
        for(int j=0; j<=i; j++){
            if(arr[j] > maxInt){
                maxInt = arr[j];
                maxIdx = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = tmp;
    }
}

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
    
    selection_sort(arr, n);
    
    printf("\n정렬된 후:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    
    return 0;
}
