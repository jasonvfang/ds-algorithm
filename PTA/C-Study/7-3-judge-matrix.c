#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n;
        int a[10][10];

        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                scanf("%d", &a[j][k]);
            }
        }

        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (a[j][k] != 0)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}