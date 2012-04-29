#ifndef _NODE_CMP_H
#define _NODE_CMP_H
#include"node.h"
#include <iostream>
using namespace std;

class nodecmp: public binary_function<node,node,bool>
{
public:
   bool operator()(const node* s1,const node* s2)const
   {
	   if(s1->length == s2->length)
	   return s1->size < s2->size;
	   else return s1->length < s2->length;
   }

};

#endif