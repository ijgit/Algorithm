/*
dp problem
1003 - fibonacci
*/

#include <stdio.h>

#define max 40

int count[2][max+1];
int idx[max+1] = {0, };

void calFibo(int n){
    if(n == 0){
        count[0][0] = 1;    count[0][1] = 0;
    }else if(n == 1){
        count[1][0] = 0;    count[1][1] = 1;
    }else{
        count[0][n] = count[0][n-2] + count[0][n-1]; 
        count[1][n] = count[1][n-2] + count[1][n-1]; 
    }
}

int main(){
    int T, n; scanf("%d", &T);
    for(int i=0; i<max+1; i++)
        calFibo(i);

    while(T--){
        scanf("%d", &n);
        printf("%d %d\n", count[0][n], count[1][n]);
    }
    return 0;
}