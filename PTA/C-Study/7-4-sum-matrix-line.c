#include <stdio.h>

int main(void)
{
    int m, n, i, j;//1=<m,n<=6
    int a[6][6] = {0};

    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    //printf("Dump:\n");
    for (i = 0; i < m; i++)
    {
        int sum = 0;
        for (j = 0; j < n; j++)
        {
            //printf("%d ", a[i][j]);
            sum += a[i][j];
        }

        printf("%d\n", sum);
    }

    return 0;
}