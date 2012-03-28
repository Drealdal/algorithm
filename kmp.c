/*
 * =====================================================================================
 *
 *       Filename:  kmp.c
 *
 *    Description:  the implement of kmp
 *
 *        Version:  1.0
 *        Created:  03/27/2012 07:35:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  drealdal (zhumeiqi), meiqizhu@gmail.com
 *        Company:  Tsinghua University, HPC
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int pf(char *str, int **next)
{
    int ret, len;
    assert( str != NULL );

    len = strlen(str);

    *next = malloc(len*sizeof(int));
    memset(*next, 0, sizeof(int)*len);

    int cur=1,p = -1,i;
    (*next)[0] = -1;
    char *ps = str+1;
    while( *ps != '\0' )
    {
	while( (p != -1) && (*ps != str[p+1]) )
	{
	    p=(*next)[p];
	}
	(*next)[cur] = p+1;

	p++;
	cur++;
	ps++;
    }

    for( i = 0; i < len; i ++ )
    {
	printf("%d ",(*next)[i]);
    }
    printf("\n");
    return len;
}

int match(char *p, char *str)
{
    int *next = NULL;
    int lp = pf(p, &next);
    int ls = strlen(str);
    int i;
    int pj = 0;
    int find = 0;
    for( i = 0; i < ls ;i++)
    {

	while( (pj != -1) && (str[i] != p[pj]) )
	{
	    pj = next[pj];
	}
	pj++;

	if(p[pj] == '\0')
	{
	    printf("find @%d:%s\n",i-pj+1,str+i-pj+1);
	    find = 1;
	    pj = next[pj-1]+1;
	}
    }
    if( find == 0 )
    {
	printf("not find");
    }
    free(next);
    return 0;
}

int main()
{
    match("aa","aaaa");
    match("abc","abcabc");
    match("abcabc","aaaaaaaaaaaaaabcabaaaaaaaabcabc");
    return 0;
}

