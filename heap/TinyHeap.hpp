/*
 * =====================================================================================
 *
 *       Filename:  tinyheap.hpp
 *
 *    Description:  the implement of heap 
 *
 *        Version:  1.0
 *        Created:  2013年11月18日 17时08分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  drealdal (zhumeiqi), meiqizhu@gmail.com
 *        Company:  Tsinghua University, HPC
 *
 * =====================================================================================
 */
#ifndef _TINY_HEAP_HPP_
#define _TINY_HEAP_HPP_
#include <stdio.h>
#include <vector>
using namespace std;
namespace THP{
    class TinyHeap;

    class HeapKey
    {
	public:
	    virtual bool little(HeapKey *node) = 0;
	    virtual void print()=0;
    };
    class HeapNode
    {
	private:
	    int pos;
	    HeapKey *key;
	    TinyHeap *pheap;
	public:
	    HeapNode( HeapKey *inkey, TinyHeap *heap)
	    {
		this->key = inkey; 
		this->pheap = heap;
	    }	
	    virtual ~HeapNode(){
		if( key != NULL )
		{
		    delete key;
		    key = NULL;
		} 
	    }
	    void setPos(int pos){this->pos = pos; }
	    int getPos(){ return this->pos;}
	    bool isValid(){ return this->pos >= 0; }
	    void unValid(){ this->pos = -1; this->pheap = NULL;}

	    TinyHeap *getHeap(){return this->pheap;}
	    void setHeap(TinyHeap *heap){
	    	this->pheap = heap;
	    }
	    HeapKey *getKey(){return this->key;}
	    /*  virtual functions */
	    virtual bool little (HeapNode *node) {
		return this->key->little(node->getKey());
	    };
	    void swap(HeapNode *node){
		int tmp = this->pos;
		this->pos = node->getPos();
		node->setPos(tmp);
	    };
	    virtual bool print_key()
	    {
		key->print();
	    }
    };

    class TinyHeap
    {
	private:
	    unsigned int max_size_;
	    unsigned int cur_size_;
	    vector<HeapNode *> content_;
	private :
	    inline HeapNode *parrent(HeapNode *node); 
	    inline HeapNode *leftc(HeapNode *node);
	    inline HeapNode *rightc(HeapNode *node); 
	    inline void shiftup(HeapNode *);
	    inline void shiftdown(HeapNode *);
	public:
	    TinyHeap(unsigned int max_size=-1);
	    ~TinyHeap();
	    HeapNode *pop();

	    bool push(HeapNode *);
	    void swap(int a, int b){
	    	HeapNode *tmp = this->content_[a];
		this->content_[a] = this->content_[b];
		this->content_[b] = tmp;
	    };

	    void dumpAll();
	    bool modifyKey(HeapNode *);
    };

};

#endif
