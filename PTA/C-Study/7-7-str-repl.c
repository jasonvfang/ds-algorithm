#include<stdio.h>

int main(void)
{
    char a[80], b[80];
    int i;

    for (i = 0; i < 80; i++)
    {
        a[i] = getchar();
        if (a[i] == '\n')
        {
            break;
        }
    }

    for (int j = 0; j < i; j++)
    {
        if (a[j] >= 'A' && a[j] <= 'Z')
        {
            b[j] = 'Z' - (a[j] - 'A');
        }
        else
        {
            b[j] = a[j];
        }
    }

    for (int j = 0; j < i; j++)
    {
        putchar(b[j]);
    }

    return 0;
}