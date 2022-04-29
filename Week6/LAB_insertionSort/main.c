
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int* arr, int arr_size){
    for(int i=1; i<arr_size; i++){
        int flg = 1;
        int selected = arr[i];
        for(int j=i-1; j>=0; j--){
            if(arr[j] < selected){
                flg = 0;
                
                for(int k=i-1; k>j; k--){
                    arr[k+1] = arr[k];
                }
                
                arr[j+1] = selected;
                break;
            }
        }
        if(flg == 1){
            
            for(int k=i-1; k>=0; k--){
                arr[k+1] = arr[k];
            }
            
            arr[0] = selected;
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
    
    insertion_sort(arr, n);
    
    printf("정렬된 후:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    
    return 0;
}
