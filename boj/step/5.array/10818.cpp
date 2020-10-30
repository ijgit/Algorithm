#include <stdio.h>

int main(){
    int N, max=-1000000, min=1000000, n; scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        scanf("%d", &n);
        max = (n > max)? n: max;
        min = (n < min)? n: min;
    }
    printf("%d %d\n", min, max);
}