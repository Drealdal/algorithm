/*
 * =====================================================================================
 *
 *       Filename:  structInit.c
 *
 *    Description:  how to give default info for struct
 *
 *        Version:  1.0
 *        Created:  2011年06月02日 09时15分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zhumeiqi (drealdal), meiqizhu@gmail.com
 *        Company:  hpc.cs.tsinghua.china
 *
 * =====================================================================================
 */
#include<stdio.h>
typedef struct test_1_s
{
	int i=2;
	int *p;
}test_1_t;
typedef struct test_2_s
{
	int i;
	int *p;
}test_2_t;
int main()
{
	test_2_t a;
	test_1_t b;
	printf("with init test_1_t: i %d p %p \n",b.i,b.p);
	printf("without init test_2_t: i %d p %p \n",a.i,a.p);
	return 0;
}
