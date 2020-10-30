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
    int max_idx = 0;
    while(T--){
        scanf("%d", &n);
        max_idx = (max_idx < n)? n:max_idx;
        idx[n] = 1;
    }
    for(int i=0; i<max_idx+1; i++){
        calFibo(i);
        if(idx[i] == 1) printf("%d %d\n", count[0][i], count[1][i]);
    }       
    return 0;
}