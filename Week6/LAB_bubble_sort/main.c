
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubble_sort(int* arr, int arr_size){
    for(int i=arr_size-1; i>0; i--){
    
        for(int j=arr_size-1; j>(arr_size - 1 - i); j--){
            if(arr[j] < arr[j-1]){
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
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
    printf("\n");
    
    bubble_sort(arr, n);
    
    printf("정렬된 후:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    
    return 0;
}
