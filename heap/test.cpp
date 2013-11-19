/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年11月19日 11时19分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  drealdal (zhumeiqi), meiqizhu@gmail.com
 *        Company:  Tsinghua University, HPC
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TinyHeap.hpp"
using namespace THP;
class IntKey:public HeapKey
{
    public:
	int key;
	IntKey(int k):key(k){}
	virtual ~IntKey(){}
	virtual bool little(HeapKey *node)
	{
	    if(node == NULL)
	    {
		return true;
	    }
	    IntKey *n = (IntKey *)node;
	    return key < n->key;
	}
	virtual void print()
	{
	    printf("%d", key);
	}

};
int main(int args, char *argv[])
{
    srand(time(NULL));
    TinyHeap h(10);

    for(int i = 0; i < 11; i++)
    {
	IntKey *k = new IntKey(rand()%100);
	HeapNode *node = new HeapNode(k, NULL);
	h.push(node);
    }
    HeapNode *tmp = NULL;

    while( (tmp = h.pop()) != NULL)
    {
	IntKey *k = (IntKey *)tmp->getKey();
	delete tmp;
	printf("%d\n",k->key);
    }
    return 0;
}
