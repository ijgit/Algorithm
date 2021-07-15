#include <stdio.h>

int main(){
    int arr[10] = {0, }, reminders[42]={0, }, max = 0, answer = 0;
    for(int i=0; i<10; i++){    scanf("%d", arr+i);}

    for(int i=0; i<10; i++){    
        reminders[arr[i]%42]++;
        max = arr[i]%42 > max ? arr[i]%42 : max;
    }
    for(int i=0; i<max+1; i++){ if(reminders[i] != 0) answer++;    }

    printf("%d\n", answer);
}