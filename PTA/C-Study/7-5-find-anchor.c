#include <stdio.h>

int main(void)
{
    int n, i, j;//1=<n<=6
    int a[6][6] = {0};
    int maxR = 0, minR = 0, idR = 0, idL = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        maxR = 0;
        for (j = 0; j < n; j++)
        {
            //max number of row
            if(a[i][j] >= maxR){
                maxR = a[i][j];
                idR = i;
                idL = j;
            }
        }
        
        minR = maxR;

        for (j = 0; j < n; j ++)
        {
           if(a[j][idL] < minR){
                minR = a[j][idL];
            }
        }

        if (minR == maxR)
        {
            //it is an anchor
            printf("%d %d\n", idR, idL);
            return 0;
        }
    }

    printf("NONE\n");

    return 0;
}
