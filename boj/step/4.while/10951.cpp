#include <stdio.h>

int main(){
    int a, b; 
    while(true){
        if(scanf("%d %d", &a, &b) == EOF) break;
        else    printf("%d\n", a+b);
    }
}