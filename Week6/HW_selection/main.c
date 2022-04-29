
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Student {
    int id;
    int korean, english, math;
} Student;

void selection_sort_by_korean(Student* arr, int arr_size){
    for(int i=arr_size-1; i>=0; i--){
        int maxInt = arr[0].korean;
        int maxIdx = 0;
        for(int j=0; j<=i; j++){
            if(arr[j].korean > maxInt){
                maxInt = arr[j].korean;
                maxIdx = j;
            }
        }
        Student tmp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = tmp;
    }
}

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    Student* stuArr = (Student *)malloc(sizeof(Student) * n);
    
    for(int i=0; i<n; i++){
        stuArr[i].id = i+1;
        stuArr[i].korean = rand() % 101;
        stuArr[i].english = rand() % 101;
        stuArr[i].math = rand() % 101;
        
        printf("korean = %d, english = %d\n", stuArr[i].korean, stuArr[i].english);
    }
    
    selection_sort_by_korean(stuArr, n);
    
    printf("\n정렬된 후:\n");
    for(int i=0; i<n; i++){
        printf("%d ", stuArr[i].korean);
    }
    printf("\n");
    
    for(int i=0; i<n; i++){
        printf("%d ", stuArr[i].english);
    }
    printf("\n");
    free(stuArr);
    
    return 0;
}
