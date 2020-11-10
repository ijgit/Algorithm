#include <stdio.h>

int main(){
    int n, _n, n_10, n_1, answer=0; 
    scanf("%d", &n); _n=n;
    do{
        n_10 = (_n/10); n_1 = (_n%10);
        _n = (n_10 + n_1)%10 + n_1*10;
        answer++;
    }while(_n!=n);

    printf("%d\n", answer);
    return 0;
}