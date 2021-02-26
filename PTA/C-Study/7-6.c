#include<stdio.h>
int main(void)
{
    char ch='0';
    int sum=0;
    
    while(ch!='\n'){
        scanf("%c",&ch);
        if(ch!='A'&&ch!='E'&&ch!='I'&&ch!='O'&&ch!='U'){
            if(ch>='A'&&ch<='Z')
                sum++;
        }
            
    }
    printf("%d",sum);
    
    return 0;
}