#include <stdio.h>
#include <string.h>

#define MAXS 10

void Shift( char s[] );

void GetString( char s[] ); /* 实现细节在此不表 */


/*
void Shift( char s[] )
{
	int len = strlen(s);

	if (len <= 3)
		return;

	char *dst = malloc(len + 1);
	
	if(dst){
		memset(dst, 0, len + 1);
		strncpy(dst, s + 3, len - 3);
		strncpy(dst + len - 3, s, 3);

		strncpy(s, dst, len);
		free(dst);
	}
}
*/
void Shift( char s[] )
{
	int len = strlen(s);

	if (len <= 3)
		return;

	int i, j = 0;
	char s1 = s[0], s2 = s[1], s3 = s[2];//backup

	for(i = 3; i < len; i ++)
	{
		s[j++] = s[i];
	}
	
	s[j] = s1;
	s[j+1]=s2;
	s[j+2]=s3;

}

int main()
{
    char s[MAXS];

    GetString(s);
    Shift(s);
    printf("%s\n", s);

    return 0; 
}