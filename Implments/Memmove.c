#include <stdio.h>
#include <string.h>

void __memmove(void *dst, void *src, size_t n)
{
	const char *pSrc = src;
	char *pDst = dst;

	/* no operation for same ptr */
	if (src == dst)	return;

	/* If src may overlap with dst then copy from backend */
	if (src < dst/* && (src + n) > dst*/)
	{

		pDst = pDst + n;
		pSrc = pSrc + n;

		while(n --)
		{
			*(-- pDst) = *(-- pSrc);
		}

	}
	else
	{
		/* If there is no overlap between dst and src, just copy from forward */
		while(n --)
		{
			*(pDst++) = *(pSrc++);
		}	
	}
}

int main(void)
{
	char string[]="abcdefghijklmnopq";
	char *src = string;
	char *dst = string + 6;

	printf("src:%s, len:%u\n", src, strlen(src));
	printf("dst:%s, len:%u\n", dst, strlen(dst));

	__memmove(dst, src, 5);

	printf("After copy:\n");
	printf("src:%s\n", src);
	printf("dst:%s\n", dst);
	
	return 0;
}

