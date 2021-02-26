#include<stdio.h>

int is_hex(char ch);            //判断是否是十六进制字符，是返回1
int hex_to_dec(char ch);        //十六进制字符转换位十进制数
int main(void)
{
    char a[80], b[80];

    int i = 0;
    while ((a[i] = getchar()) != '#')
    {
        i++;
    }

    int j = 0;
    int count = 0;                //十六进制字符的个数
    int first_hex = -1;            //第一个十六进制字符的下标
    for (i = 0; a[i] != '#'; i++)
    {
        if (is_hex(a[i]))
        {
            count++;
            if (count == 1)
            {
                first_hex = i;
            }
            b[j] = a[i];
            j++;
        }
    }

    int flag = 1;                //等于-1时，表示负数
    for (i = 0; i < first_hex; i++)
    {
        if (a[i] == '-')
        {
            flag = -1;
        }
    }

    int num = 0;
    for (i = 0; i < j; i++)
    {
        num = num * 16 + hex_to_dec(b[i]);
    }

    num = flag * num;
    printf("%d", num);

    return 0;
}
int is_hex(char ch)
{
    int ret = 0;
    if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f'))
    {
        ret = 1;
    }

    return ret;
}
int hex_to_dec(char ch)
{
    int ret = 0;
    if (ch >= '0' && ch <= '9')
    {
        ret = ch - '0';
    }
    else if (ch >= 'A' && ch <= 'F')
    {
        ret = 10 + ch - 'A';
    }
    else if (ch >= 'a' && ch <= 'f')
    {
        ret = 10 + ch - 'a';
    }

    return ret;
}