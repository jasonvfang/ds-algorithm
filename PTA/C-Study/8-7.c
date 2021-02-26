#if 1
#include<stdio.h>
#include<string.h>
#define M 5
#define N 80
int main()
{
    char str[M][N],tmp[N];
    int i,j,pos;
    for(i=0;i<M;i++){
    scanf("%s",&str[i]);
    }
    /*选择排序*/
    for(i=0;i<M;i++){
    	pos=i;
    	for(j=i+1;j<M;j++){
    		if(strcmp(str[j],str[pos])<0){
    			pos=j;
			}
		}
		    strcpy(tmp,str[pos]);
			strcpy(str[pos],str[i]);
			strcpy(str[i],tmp);
	}
    printf("After sorted:\n");
    for(i=0;i<M;i++){
        printf("%s\n",str[i]);
    }
    return 0;
 } 

 #else
#include<stdio.h>
#include<string.h>

#define M 5
#define N 80
int main()
{
    char str[M][N],tmp[N];
    int i,j,pos,f;
    for(i=0;i<M;i++){
    scanf("%s",&str[i]);
    }
    /*插入排序*/
	for(i=1;i<M;i++){
		if(strcmp(str[i],str[i-1])<0){
			strcpy(tmp,str[i]);
			f=i;
		for(;f>=1&&strcmp(tmp,str[f-1])<0;f--){
			 strcpy(str[f],str[f-1]);
		   } 
		     strcpy(str[f],tmp);
        }
	} 
    printf("After sorted:\n");
    for(i=0;i<M;i++){
        printf("%s\n",str[i]);
    }
    return 0;
 } 

 #endif