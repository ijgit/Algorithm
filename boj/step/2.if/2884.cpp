#include <stdio.h>

int main(){
    int h, m; scanf("%d %d", &h, &m);

    m -= 45;
    if(m < 0){
        h -= 1;
        if(h < 0) h += 24;
        
        m += 60;
    }
    printf("%d %d\n", h, m);
    return 0;
}