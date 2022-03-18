#include <stdio.h>

void echo1(){
    int ch;
    while((ch = getchar()) != '\n'){
        putchar(ch);
    }
}

void echo2(){
    int ch;
    while((ch = getchar()) != '\n'){
        putchar(ch);
        echo2();
    }
}

int main(int argc, const char * argv[]) {
    
    printf("Enter a String and press enter : ");
    echo1();
    
    printf("\nEnter a String and press enter : ");
    echo2();
    
    return 0;
}
