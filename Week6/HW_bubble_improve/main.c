
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubble_sort(int* arr, int arr_size){
    for(int i=0; i<arr_size-1; i++){
        printf("i = %d: ", i);
        for(int j=0; j<(arr_size - 1 - i); j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
            
        }
        for(int k=0; k<arr_size; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
        
        int flg = 1;
        for(int k=0; k<arr_size-1; k++){
            if(arr[k] > arr[k+1]){
                flg = 0;
                break;
            }
        }
        
        if(flg == 1){
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    int* arr = (int *)malloc(sizeof(int) * n);
    
    printf("초기 : ");
    for(int i=0; i<n; i++){
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bubble_sort(arr, n);
    
    printf("정렬 : ");
    for(int k=0; k<n; k++){
        printf("%d ", arr[k]);
    }
    printf("\n");
    free(arr);

    
    return 0;
}
