
#include <stdio.h>

int isIn(int answers[2],  int idx, int answer_idx){
    int i;
    
    for(i=0; i<answer_idx; i++){
        if(answers[i] == idx){
            return 1;
        }
    }
    return 0;
}

void soonyeol(char groups_total[][10], int answers[2], int total, int last, int answer_idx){
    int i, j;
    
    if(last == 0){
        for(i=0; i<2; i++){
            printf("%s\t", groups_total[answers[i]]);
        }
        printf("\n");
        return;
    }
    
    for(j=0; j<total; j++){
        if(!isIn(answers, j, answer_idx)){
            answers[answer_idx] = j;
            soonyeol(groups_total, answers, total, last-1, answer_idx+1);
        }
    }
}

int main(void) {
    
    int n;
    
    char groups[5][10] = {"공유","김수현","송중기", "지성", "현빈"};
    int answers[2];
    
    scanf("%d", &n);
    
    soonyeol(groups, answers, 5, n, 0);
    
    return 0;
}
