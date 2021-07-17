#include <stdio.h>

int main(){
    int N = 0, tmp = 0, score = 0;
    char oxstr[81] = "";

    scanf("%d", &N);
    for(int i=0; i<N; i++){
        score = 0, tmp = 0;
        scanf("%s", oxstr);

        for(int i=0; oxstr[i] != 0 && i <81; i++){
            if(oxstr[i] == 'O'){
                tmp++;
                score += tmp;
            }
            else{ tmp = 0;}
        }
        printf("%d\n", score);
    }
}