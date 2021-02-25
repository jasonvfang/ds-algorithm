#include<stdio.h>  
#include<string.h>  

int main()
{  
    char c, str[128] = {0};
    int i = 0, idx = -1, find = 0;

    scanf("%c\n", &c);

    while (( str[i] = getchar()) != '\n')
        i++;

    str[i] = '\0';

    for (i = 0; str[i] != '\0'; i ++)
    {
        if (c == str[i])
        {
            idx = i;
            find = 1;
            break;
        }
    }

    if (!find)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("index = %d\n", idx);
    }

    return 0;   
}



