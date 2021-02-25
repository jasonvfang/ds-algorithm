#include <stdio.h>

int main()
{
    int n, m, i, j;

    scanf("%d", &n);
    m = n / 2 + 1;

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= m - i; j++)
        {
           printf("  ");
        }

        for (j = 1; j <= 2 * i - 1; j++)
        {
            printf("* ");
        }

        printf("\n");
    }

    for (i = 1; i < m; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("  ");
        }

        for (j = 1; j <= 2 * (m - i) - 1; j++)
        {
             printf("* ");
        }

        printf("\n");
    }

    return 0;
}