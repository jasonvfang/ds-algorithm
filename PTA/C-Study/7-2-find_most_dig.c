#include<stdio.h>

int count[10] = {0};
int max_count = 0;

void count_digits(int a)
{
    int t = 0, base = 10;
    int r;
    
    while (a != 0)
    {
        t = a / base;
        r = a % base;
        count[r] ++;
        a = t;

        if (count[r] > max_count)
        {
            max_count = count[r];
        }
    }
}

int main(void)
{
    int n, i;
    int a[11] = {0};
    
    scanf("%d\n",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        count_digits(a[i]);
    }

    printf("%d:", max_count);
    for(i = 0;i < 10; i ++){
        if(count[i] == max_count){
            printf(" %d", i);
        }
    }

    return 0;    
}
