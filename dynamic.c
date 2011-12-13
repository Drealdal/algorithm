/*
 * =====================================================================================
 *
 *       Filename:  dynamic.c
 *
 *    Description:  Assignment 1
 *
 *        Version:  1.0
 *        Created:  2011年04月17日 15时25分02秒
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
#define MAXN (100001)
int main()
{
	int maxlen=0,curmaxlen=0;
	int n,i,j;
	int val[MAXN],len[MAXN];
	memset(val,0,sizeof(val));
	memset(len,0,sizeof(len));
	scanf("%d",&n);
	for(i=0; i<n ;i++ )
	{
		int a;
		scanf("%d",&val[i]);
		len[i]=1;
		a=val[i];

		for(j=i-1;j>=0;j--)
		{
			if(val[j]<a)
			{
				len[i]=(len[j]+1)>len[i]?(len[j]+1):len[i];
			}
		}

	}
	int maxx=1;
	for(i=0;i<n;i++)
	    maxx=maxx>len[i]?maxx:len[i];
	printf("%d\n",maxx);
	return 0;
}
