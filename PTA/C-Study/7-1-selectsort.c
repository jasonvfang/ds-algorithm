#include<stdio.h>
int main(void)
{
    int n,i, j;
    int a[10];
    int tem;
    
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }    
    
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[j]>a[i])
            {
                tem=a[i];
                a[i]=a[j];
                a[j]=tem;
            }
        }
    }

    printf("%d",a[0]);
    for(i=1;i<n;i++){
        printf(" %d",a[i]);
    }    
    return 0;    
}
