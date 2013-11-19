/*
 * =====================================================================================
 *
 *       Filename:  TinyHeap.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年11月18日 17时50分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  drealdal (zhumeiqi), meiqizhu@gmail.com
 *        Company:  Tsinghua University, HPC
 *
 * =====================================================================================
 */
#include "TinyHeap.hpp"
namespace THP
{
    TinyHeap::TinyHeap(unsigned int max_size):max_size_(max_size), cur_size_(0)
    {
    }

    TinyHeap::~TinyHeap(){}
    
    inline HeapNode * TinyHeap::parrent(HeapNode *node)
    {
	int p = node->getPos();
	if( p == 0)
	{
	    return NULL;
	}
	return this->content_[p/2];
    }

    inline HeapNode * TinyHeap::leftc(HeapNode *node)
    {
	int p = node->getPos();
	if( 2 * p + 1 >= this->cur_size_ )
	{
	    return NULL;
	}
	return this->content_[2 * p + 1];
    }

    inline HeapNode *TinyHeap::rightc(HeapNode *node)
    {
	int p = node->getPos();
	if( 2 * p + 2 >= this->cur_size_ )
	{
	    return NULL;
	}
	return this->content_[2 * p +2];
    }

    void TinyHeap::shiftup(HeapNode *node)
    {
	HeapNode *p = this->parrent(node);
	if( p == NULL )
	    return;
	else{
	    if( node->little( p ) )
	    {
		node->swap(p);
		swap(node->getPos(), p->getPos());
	    	shiftup(node);
	    }
	}
    }

    void TinyHeap::shiftdown(HeapNode *node)
    {
	HeapNode *l = this->leftc(node);
	HeapNode *p = NULL;
	if( l == NULL )
	{
	    return;
	}
	HeapNode *r = this->rightc(node);
	if(r == NULL)
	{ 
	    p = l;
	}else{
	    if( l -> little(r))
	    {
		p = l;
	    }else{
		p = r;
	    }
	}
	if( !node->little(p) )
	{
	    node->swap(p);
	    swap(node->getPos(), p->getPos());
	    shiftdown(node);
	}
    }

    bool TinyHeap::modifyKey(HeapNode *node)
    {
	if(node == NULL || node->getHeap() != this)
	{
	    return false;
	}
	this->shiftup(node);
	this->shiftdown(node);
	return true;
    }

    HeapNode *TinyHeap::pop()
    {
	if( this->cur_size_ <= 0 )
	{
	    return NULL;
	}

	this->content_[0]->swap(this->content_[this->cur_size_ - 1]);
	swap(0, this->cur_size_ - 1);
	HeapNode *ret = this->content_[this->cur_size_ - 1];
	this->cur_size_ -= 1;
	this->shiftdown(this->content_[0]);
	this->content_.pop_back();

	ret->unValid();
	return ret;
    }

    bool TinyHeap::push(HeapNode *node)
    {
	if( this->cur_size_ >= this->max_size_ ||\
	       	node == NULL || node->getKey() == NULL)
	{
	    return false;
	}
	node->setPos(this->cur_size_);
	this->content_.push_back(node);
	node->setHeap(this);
	this->cur_size_++;

	this->shiftup(node);
	return true;
    }
    void TinyHeap::dumpAll()
    {
	for(int i = 0; i < this->cur_size_; ++i)
	{
	    this->content_[i]->print_key();
	    printf("\t");
	}
	printf("\n");
    }
};
