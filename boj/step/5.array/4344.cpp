#include <stdio.h>

int main(){
    int C, N, answer; scanf("%d", &C);
    float mean = 0;

    for(int i=0; i<C; i++){
        mean = 0; answer = 0;
        scanf("%d", &N);
        int stus[N];

        for(int j=0; j<N; j++){
            scanf("%d", stus+j);
            mean += stus[j];
        } 
        mean /= N;
        for(int j=0; j<N; j++){
            if(stus[j] > mean) answer++;
        }

        printf("%.3f%\n", (float)answer/N*100);
    }

    return 0;
}