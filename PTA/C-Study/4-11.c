#include <stdio.h>

int main(int argc, char *argv[])
{

	int a=1,b=1,n,t=1,i=2;
    scanf("%d",&n);
	
    if(n==1) 
	{
		printf("1");
	}
	else
	{
		while(n>t)
		{
			i++; 
			t=a+b;
			b=a;
			a=t;
			
		} 
		printf("%d",i);
	}

	return 0;
}