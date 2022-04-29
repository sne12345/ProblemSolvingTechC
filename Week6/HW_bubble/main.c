
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Student {
    int id;
    int korean, english, math;
} Student;

void bubbleSortAscendingById(Student* arr, int arr_size){
    for(int i=arr_size-1; i>0; i--){
    
        for(int j=arr_size-1; j>(arr_size - 1 - i); j--){
            if(arr[j].id < arr[j-1].id){
                Student tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
}

void bubbleSortDescendingByKorean(Student* arr, int arr_size){
    for(int i=arr_size-1; i>0; i--){
    
        for(int j=arr_size-1; j>(arr_size - 1 - i); j--){
            if(arr[j].korean > arr[j-1].korean){
                Student tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
}

void bubbleSortDescendingByMath(Student* arr, int arr_size){
    for(int i=arr_size-1; i>0; i--){
    
        for(int j=arr_size-1; j>(arr_size - 1 - i); j--){
            if(arr[j].math > arr[j-1].math){
                Student tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
}

void bubbleSortDescendingByEnglish(Student* arr, int arr_size){
    for(int i=arr_size-1; i>0; i--){
    
        for(int j=arr_size-1; j>(arr_size - 1 - i); j--){
            if(arr[j].english > arr[j-1].english){
                Student tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
}

void printArr(Student* stuArr, int n){
    
    for(int i=0; i<n; i++){
        printf("학번 : %d\t", stuArr[i].id);
        printf("영어 : %d\t", stuArr[i].english);
        printf("수학 : %d\t", stuArr[i].math);
        printf("국어 : %d\n", stuArr[i].korean);
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    int n;
    printf("학생 수를 입력하세요 : ");
    scanf("%d", &n);
    
    Student* stuArr = (Student *)malloc(sizeof(Student) * n);
    
    for(int i=0; i<n; i++){
        stuArr[i].id = i+1;
        stuArr[i].korean = rand() % 101;
        stuArr[i].english = rand() % 101;
        stuArr[i].math = rand() % 101;
    }
    printArr(stuArr, n);
    
    while(1){
        printf("정렬 기준 선택<1:국어, 2:수학, 3:영어, 4:id<오름차순>, 0:끝내기> : ");
        int command;
        scanf("%d", &command);
        if(command == 0){
            break;
        }
        
        switch (command) {
            case 1:
                bubbleSortDescendingByKorean(stuArr, n);
                printArr(stuArr, n);
                break;
            case 2:
                bubbleSortDescendingByMath(stuArr, n);
                printArr(stuArr, n);
                break;
            case 3:
                bubbleSortDescendingByEnglish(stuArr, n);
                printArr(stuArr, n);
                break;
            case 4:
                bubbleSortAscendingById(stuArr, n);
                printArr(stuArr, n);
                break;
            default:
                break;
        }
    }
    free(stuArr);
    
    return 0;
}
