#include <stdio.h>

void dumpArray(int *a, int len)
{
    int i;
    printf("Array:\n");
    for(i = 0; i < len; i ++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int i, n1, n2, j, k = 0; 
    int a[21]={0}, b[21]={0}, c[21] = {0};

    scanf("%d", &n1);
    for(i = 0; i < n1; i ++){
        scanf("%d", &a[i]);
    }
    
    dumpArray(a, n1);

    scanf("%d", &n2);
    for(i = 0; i < n2; i ++){
        scanf("%d", &b[i]);
    }

    dumpArray(b, n2);

    //find the unique number of two array
    for(i = 0; i < n1; i ++)
    {
        int isUnique = 1;
        for(j = 0; j < n2; j ++)
        {
            if(a[i] == b[j])
            {
                isUnique = 0;
                break;
            }
        }

        if (isUnique){
            c[k] = a[i];
            k ++;
        }
    }

    printf("%d", c[0]);
    for(i = 1; i < k; i ++)
    {
        printf(" %d", c[i]);
    }
    printf("\n");

	return 0;
}
