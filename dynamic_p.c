姓名：祝美祺  学号：2010210735 
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

//执行结果
zhumeiqi@okuta:~/workspace/algorithm$ time ./dynamic <test-data/1-in.txt 
5

real	0m0.002s
user	0m0.004s
sys	0m0.004s
zhumeiqi@okuta:~/workspace/algorithm$ time ./dynamic <test-data/2-in.txt 
21

real	0m0.003s
user	0m0.004s
sys	0m0.000s
zhumeiqi@okuta:~/workspace/algorithm$ time ./dynamic <test-data/3-in.txt 
55

real	0m0.010s
user	0m0.012s
sys	0m0.000s
zhumeiqi@okuta:~/workspace/algorithm$ time ./dynamic <test-data/4-in.txt 
203

real	0m0.305s
user	0m0.304s
sys	0m0.000s
zhumeiqi@okuta:~/workspace/algorithm$ time ./dynamic <test-data/5-in.txt 
604

real	0m28.491s
user	0m28.402s
sys	0m0.008s

