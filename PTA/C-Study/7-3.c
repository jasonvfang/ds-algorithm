#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, i; 
    int a[16]={0};

    scanf("%d", &n);
    for(i = 0; i < n; i ++){
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n / 2; i ++)
    {
        int t = a[i];
        a[i] = a[n -i - 1];
        a[n - i - 1] = t;
    }
    
    printf("%d", a[0]);
    for(i = 1; i < n; i ++)
    {
        printf(" %d", a[i]);
    }

    printf("\n");

	return 0;
}
