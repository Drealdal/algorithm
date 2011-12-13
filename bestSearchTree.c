/*
 * =====================================================================================
 *
 *       Filename:  bestSearchTree.c
 *
 *    Description:  最优二分搜索树
 *
 *        Version:  1.0
 *        Created:  2011年05月12日 15时59分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhumeiqi (drealdal), meiqizhu@gmail.com
 *        Company:  hpc.cs.tsinghua.china
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 100  //number of node
#define FILENAME "bestSearchInput.txt"
double p[N+10];
double q[N+10];
double w[N+10][N+10];
double e[N+10][N+10];
int root[N+10][N+10];
static int getInput();
double solve(int n);
void printTree(int  n,int m);
void printAll(int numx , int numy);
int main()
{
	int num;
	printf("Get %d input \n",num=getInput());
	printf("Best Answer: %lf \n",solve(num));
	return 0;
}
double solve(int n)
{
	double re = 0.0;
	int i,j,r,l;
	for(i=1;i<=n+1;i++)
	{
		e[i][i-1]=q[i-1];
		w[i][i-1]=q[i-1];
	}
//	printf("%lf %d %lf\n",e[6][5],n,q[i-1]);
	for(l=1;l<=n;l++)
	{
		for( i = 1;i+l<=n+1;i++)
		{
			e[i][i+l-1]=INT_MAX;
			w[i][i+l-1]=w[i][i+l-2]+p[i+l-1]+q[i+l-1];
			for(r=i;r<=i+l-1;r++)
			{
				double t = e[i][r-1]+e[r+1][i+l-1]+w[i][i+l-1];
		//		printf("i:%d r:%d j:%d e[i][r-1]:%lf e[r+1][j]:%lf w[i][j]:%lf t:%lf\n",i,r,i+l-1,e[i][r-1],e[r+1][r+l-1],w[i][i+l-1],t);
				if(t<e[i][i+l-1])
				{
					e[i][i+l-1]=t;
					root[i][i+l-1]=r;
				}
			}
		}
	}

	printAll(n+1,n+1);
	printTree(n,n);
	re=e[1][n];
	return re;
}
static int getInput()
{
	FILE * file = NULL;
	file = fopen(FILENAME,"r");
	if(file == NULL )
	{
		printf("Open file %s failed at %s line:%d\n",FILENAME,__FILE__,__LINE__);
		exit(0);
	}
	int i,re = 0;
	if(fscanf(file, "%d" ,&re )==EOF)
	{
		printf("Input error at %s %d \n",__FILE__,__LINE__);
		exit(0);
	}

	for(i=0;i<re;i++)
	{
		if(fscanf(file,"%lf",&p[i+1])==EOF)
		{
			printf("%d th Input Error at %s Line %d \n ",i, __FILE__,__LINE__);
			exit(1);
		}
	}
	for(i=0;i<re+1;i++)
	{
		if(fscanf(file,"%lf",&q[i])==EOF)
		{
			printf("%d th Input Error at %s Line %d \n ",i, __FILE__,__LINE__);
			exit(1);
		}
	}
	return re;
}
void printAll(int numx,int numy)
{
	int i,j;
	for(i=1;i<=numx;i++)
	{
		for(j=0;j<=numy;j++)
		{
			printf("\t%lf",e[i][j]);
		}
		printf("\n");
	}
}
void printTree(int numx,int numy)
{
	int i,j;
	for(i=1;i<=numx;i++)
	{
		for(j=1;j<=numy;j++)
		{
			printf("\t%d",root[i][j]);
		}
		printf("\n");
	}
}
