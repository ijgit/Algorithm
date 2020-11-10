#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    for(int _b = b; _b>0; _b/=10){
        printf("%d\n", a * (_b%10));
    }
    printf("%d\n", a*b);
    return 0;
}