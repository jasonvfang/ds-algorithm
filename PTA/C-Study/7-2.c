#include <stdio.h>

int main()
{
    int n = 0, max = 0, id = 0;
    int *a = NULL;
    
    scanf("%d", &n);
    
    if(n > 0)
    {
        a = (int *)malloc(n * sizeof(int));
        if(a)
        {
            int i = 0;
            scanf("%d", &a[0]);

            max = a[0];
            id = 0;
            i ++;

            while(i < n)
            {
                scanf("%d", &a[i]);
                
                if(a[i] > max){
                    max = a[i];
                    id = i;
                }
                
                i ++;
            }

            free(a);
        }
    }

    printf("%d %d\n",max, id);
    
    return 0;
}