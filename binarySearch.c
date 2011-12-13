/*
 * =====================================================================================
 *
 *       Filename:  binarySearch.c
 *
 *    Description:  baniary search
 *
 *        Version:  1.0
 *        Created:  2011年05月09日 14时52分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhumeiqi (drealdal), meiqizhu@gmail.com
 *        Company:  hpc.cs.tsinghua.china
 *
 * =====================================================================================
 */
#include<stdio.h>
#include<stdlib.h>
#define INPUTFILE "./Input.txt"
int findX(int key,const int * data , int num);
static 	cmp(const void * aI , const void * bI)
{
	int a = *(int *)aI;
	int b = *(int *)bI;
	if(a==b)return 0;
	if(a<b) return -1;
	if(a>b) return 1;
}
int main(int argc , char * argv[])
{
	if(argc <2)
	{
		printf("usage : <x>");
		return -4;
	}
	int x = atoi(argv[1]);
	FILE * f = fopen(INPUTFILE,"r");
	int re=-1;
	if(f==NULL){
		printf("open file failed\n");
		return -1;
	}
	int i, j, n , *numbers;
       	if(fscanf(f,"%d",&n)==EOF)
	{
		printf("Input Error\n");
		return -2;
	}
	
	numbers = (int *) malloc(n*sizeof(int));
	if(numbers == NULL )
	{
		printf("malloc error at %s %d \n",__FILE__,__LINE__);
	}
	for(i=0; i < n ;i ++)
	{
		if(fscanf(f,"%d",numbers+i)==EOF)
		{
			printf("Input Error at %s %d \n",__FILE__,__LINE__);
			return -3;
		}
	}
	qsort(numbers , n , sizeof(int),cmp);
	for(i=0; i<n;i++)
		printf("\t %d",*(numbers+i));
	printf("\n");
	re = findX(x,numbers,n);
	if(re!=-1)
	{
		printf("First Pos of %d is :%d\n",x,re+1);
	}else{
		printf("Not Found\n");
	}
	fclose(f);
	return 0;
}

int findX(int Key,const int * data , int num)
{
	int begin=0;
	int end=num-1;
	int tmp,mid;
	while(end>begin)
	{
		mid=(end+begin)/2;
		tmp=*(int *)(data+mid);
		printf("Begin: %d End:%d Mid: %d Tmp:%d Key:%d\n",begin,end,mid,tmp,Key);
		if(tmp>Key)
		{
			end=mid-1;
		}else if( tmp == Key ){
			end=mid;
		}else {
			begin=mid+1;
		}
	}
	if(end<begin)return -1;

	tmp=*(int * ) (data+begin);
	if( ( end ==  begin )&& (Key !=tmp) )
		return -1;
	printf("Begin: %d End:%d Mid: %d Tmp:%d Key:%d\n",begin,end,mid,tmp,Key);
	return begin;
}
