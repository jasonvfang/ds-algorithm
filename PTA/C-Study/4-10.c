#include <stdio.h>

int main(){

    int n, sum=1;
    scanf("%d", &n);
    while(n>1)
    {
        //共吃了n-1天，还有一天没吃
        //printf("第 %d 天， 还剩 %d 桃\n", n, sum);
        sum = (sum+1)*2;
        n--;
    }
    printf("%d\n", sum);
    return 0;
}
