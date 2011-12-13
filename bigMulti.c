/*
 * =====================================================================================
 *
 *       Filename:  bigMulti.c
 *
 *    Description: 大数乘法  
 *
 *        Version:  1.0
 *        Created:  2011年05月29日 15时25分54秒
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
#include<string.h>
#define MAXN 1000
int multi(int A[] , int B[] ,int C[])
{
	int la , lb ,i ,j ;
	la = MAXN-1;
	lb = MAXN-1;
	while(A[la]==0)la--;
	while(B[lb]==0)lb--;
	for(i=0;i<MAXN;i++)
		C[i]=0;
	for(j=lb;j>=0;j--)
	{
		if(C[MAXN-1]!=0)
		{
			printf("over flow\n");
			exit(1);
		}
		for(i=MAXN-1;i>0;i--)
			C[i]=C[i-1];
		C[0]=0;	
		for ( i =0 ; i <=la ;i++)
		{
			C[i]+=A[i]*B[j];
			if(C[i]>10)
			{
				C[i+1]+=C[i]/10;
				C[i]=C[i]%10;
			}
		}
	}
	for(i=0;i<MAXN-2;i++)
	{
		C[i+1]+=C[i]/10;
		C[i]=C[i]%10;
	}
	return 0;
}
void initData(int A[]);
void printData(int A[]);
int main()
{
	
	int A[MAXN],B[MAXN],C[MAXN];
	initData(A);
	initData(B);
	multi(A,B,C);
	printData(C);
	return 0;
}
void initData(int A[])
{
	char tmp[MAXN];
	int i,j=0;
	scanf("%s",tmp);
	for(i=0;i<=MAXN-1;i++)
		A[i]=0;
	for(i=strlen(tmp)-1;i>=0;i--)
	{
		if(tmp[i]<'0'||tmp[i]>'9')
		{
			printf("wrong char\n");
			exit(2);
		}
		A[j++]=tmp[i]-'0';
	}
}

void printData(int A[])
{
	int i=MAXN-1;
	while(A[i]==0)i--;
	while(i>=0)
	{
		printf("%d",A[i]);
		i--;
	}
	printf("\n");
	
}
