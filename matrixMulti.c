/*
 * =====================================================================================
 *
 *       Filename:  matrixMulti.c
 *
 *    Description:  矩阵链乘解决方案
 *
 *        Version:  1.0
 *        Created:  2011年05月12日 14时06分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhumeiqi (drealdal), meiqizhu@gmail.com
 *        Company:  hpc.cs.tsinghua.china
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define N 100  // at most N matrix
#define FILENAME "matrixInput.txt"
int Dims[N];
int map[N+10][N+10];
int solve(),n;
void addKuohao(int a, int b);
static void printMap( int X , int Y);
int getInput()
{
	FILE * file = fopen(FILENAME,"r");
	if(file == NULL )
	{
		printf("open file: %s  failed at : file %s line %d \n",FILENAME,__FILE__,__LINE__);
	}
	int re,i;
	if(fscanf(file,"%d",&re)==EOF){
		printf("Error input at : file %s line %d\n",__FILE__,__LINE__);
	}
	for( i=0 ; i<re ; i++)
	{
		if(fscanf(file , "%d ", &Dims[i])==EOF )
		{
			printf("Error input at : file %s line %d\n",__FILE__,__LINE__);
		}
		printf("%d ",Dims[i]);
	}
	printf("\n");
	return re;

}
int main()
{

	printf("Get %d number \n",n=getInput());
	solve();
	return 0;
}

int solve()
{
	int d , i , j ;
	for(i=0;i<n-1;i++)
		map[i][i]=0;
	for( d = 1 ; d< n-1 ;d ++ )
	{
		for(i=0;i+d<n-1;i++)
		{
			map[i][i+d]=INT_MAX;
			for(j=i+1;j<=i+d;j++)
			{
				int tmp =map[i][j-1]+map[j][i+d]+Dims[i]*Dims[j]*Dims[i+d+1];
				map[i][i+d]=map[i][i+d]>tmp?tmp:map[i][i+d];
			}
		}
	}
	//printMap(n,n);
	printf("The least mul operation counts is : %d\n",map[0][5]);
	addKuohao(0,n-2);
	printf("\n");
}
void addKuohao(int start ,int end)
{
	if(start==end)
	{
		printf("[%d,%d]",Dims[start],Dims[start+1]);
		return;
	}
	printf("(");
	int i,find=0;
	for( i=start;i<=end;i++)
	{	
		if(map[start][i]+map[i+1][end]+Dims[start]*Dims[i+1]*Dims[end+1]==map[start][end])
		{
			addKuohao(start,i);
			printf("*");
			addKuohao(i+1,end);
			find=1;
		}
	}
	if(!find){
		printf("Error Map\n");
	}

	printf(")");
}
static void printMap(int X ,int Y)
{
	int i , j ;
	for(i=0;i<X;i++)
	{
		for(j=0;j<Y;j++)
			printf("\t%d",map[i][j]);
		printf("\n");
	}
}




