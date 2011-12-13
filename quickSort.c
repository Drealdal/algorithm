/*
 * =====================================================================================
 *
 *       Filename:  quickSort.c
 *
 *    Description:  quick sort
 *
 *        Version:  1.0
 *        Created:  2011年06月14日 15时31分55秒
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
void swap(int *a , int *b)
{
	printf("swap: %d %d\n",*a,*b);
	int t=*a;
	*a=*b;
	*b=t;
}
int p(int *A,int b,int e)
{
	int i;
	for(i=b;i<e;i++)
		printf("%d ",A[i]);
	printf("\n");
}
int quickSort(int *A,int begin,int end)
{
	if(A==NULL||end<=begin+1)
		return 1;
	int x = A[begin];
	int i=begin,j=end-1;
	do{
		while(i<end&&A[i]<=x)i++;
		while(j>=begin&&A[j]>x)j--;
		if(i<j)
		swap(&A[i],&A[j]);
	}while(i<j);
		
	swap(&A[begin],&A[j]);
	p(A,begin,end);
	quickSort(A,begin,j-1);
	quickSort(A,i,end);

	return 1;
}
int main()
{
	int i,A[]={5,20,3,40,5,6,2,7,8,2,3,5,2,4};
	p(A,0,14);
	quickSort(A,0,14);
	for(i =0 ;i < 14;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}
