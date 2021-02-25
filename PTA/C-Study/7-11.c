#include<stdio.h>  
#include<string.h>  

#define MAX_LEN 80

int main()
{  
    char str[MAX_LEN] = {0}, c='\0';
    int i = 0, len = 0;

    while(c!='\n'){
        scanf("%c",&c);
        str[len++]=c;
    }

    str[len] = '\0';

    for (i = 0; i < len / 2; i ++)
    {
        char t = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = t;
    }

    printf("%s", str);
    return 0;   
}



