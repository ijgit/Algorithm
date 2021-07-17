#include <stdio.h>

int main(){
    int N, max=0;  scanf("%d", &N);
    float mean = 0;
    int records[N];
    
    for(int i=0; i<N; i++){ 
        scanf("%d", records+i);
        max = (max > records[i])? max:records[i];
    }
    for(int i=0; i<N; i++){ mean += (float)records[i]/max*100; }
    printf("%.3f\n", mean/N);

    return 0;
}