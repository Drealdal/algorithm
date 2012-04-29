#include "node.h"
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
#define INT_MAX 0Xefff

node * node::go()
{

	int i,j,k;
	int cCost = 0;

	this->cur = 0;

	while(this->val[this->cur] != this->cur_pos && this->cur < this->size ) this->cur++;
	if(this->cur >= this->size) return NULL;
	int rMin = INT_MAX;
	int find = false;
	for(j=0;j<size;j++)
	{
		if(this->matrix[this->cur][j] >=0 && this->matrix[this->cur][j] < rMin)
		{
			rMin = this->matrix[this->cur][j];
		}
	}
	for(j=0;j<size;j++)
	{
		if(this->matrix[this->cur][j] >=0 )
		{
			this->matrix[this->cur][j] -=rMin;
			find = true;
		}
	}
	if(!find) return NULL;
	cCost+=rMin;

	// 每列至少一个0
	
	for( j = 0 ;j < this->size; j++)
	{
		int mc = INT_MAX;
		for(i=0;i<this->size;i++)
		{
			if(this->matrix[i][j] >=0 && this->matrix[i][j] < mc )
			{
				mc = this->matrix[i][j];
			}
		}
		for(i=0;i<this->size;i++)
		{
			if(this->matrix[i][j] >=0  )
			{
				 this->matrix[i][j] -= mc;
			}
		}
		if(mc != INT_MAX)
		cCost+=mc;
	}


	j = 0;
	int jm=0, cm=0;
	while( this->matrix[this->cur][j] != 0 )j++;
	int tmp = 0;
	if(this->size == this->pSize)
	{
		while( this->val[jm] != this->valC[j]) jm++;
		while( this->valC[cm] != this->cur_pos) cm++;
		 tmp = this->matrix[jm][cm];
	}

	k=j;
	this->matrix[this->cur][j] = -1;
	this->answer[this->length] = this->val[this->cur];
	

	
	node * nl = new node();
	this->cost+=cCost;
	nl->cost = this->cost;
	nl->pSize = this->pSize;
	nl->size = this->size - 1;
	nl->cur_pos = this->valC[k];


	nl->answer = new int[sizeof(int)*pSize];
	memcpy(nl->answer,this->answer,sizeof(int)*pSize);
	nl->length = this->length+1;
	nl->cur = k;

	nl->val = new int [nl->size];
	nl->valC = new int [nl->size];
	nl->matrix = new int *[nl->size];
	for( i = 0 ; i < nl->size ; i++)
	{
		nl->matrix[i] = new int[nl->size];
	}
	int ii=0,jj=0;
	int jk = 0;
	if(nl->cur > this->cur) nl->cur--;
	for( i = 0; i < this->size; i++)
	{
		  if( i != k )
		{
			nl->valC[jk++] = this->valC[i];
		}
		if( i == this->cur)
		{
				continue;
		}
		jj = 0;
		for( j = 0 ; j < this->size; j ++)
		{
			if( j == k)
			{
				continue;
			}
			nl->matrix[ii][jj++] = this->matrix[i][j];
		}
		nl->val[ii++] = this->val[i]; 
	  
	}
	if(this->size == this->pSize)
	{
		this->matrix[jm][cm] = tmp;
	}
	nl->print();
	return nl;
}

node::node(){};
node::node(ifstream &fin)
{
	fin>>this->size;
	this->pSize = this->size;
	this->cost = 0;
	this->cur_pos =1 ;

	this->val = new int[this->size];
	this->valC = new int [this->size];
	this->answer = new int [this->size];
	this->matrix = new int *[this->size];
	for(int i = 0; i < this->size ; i++)
	{
		this->val[i] = i+1;
		this->valC[i] = i+1;
		this->matrix[i]= new int[this->size];
		for( int j = 0 ; j < this->size; j++)
		{
			fin>>this->matrix[i][j];
			if( i == j ) this->matrix[i][j] = -1;
		}
	}
	this->cur = 0;
	this->length = 0;
}

node::~node()
{
	delete(this->answer);
	delete(this->val);
	for( int i = 0 ;i < this->size; i++)
	{
		delete(this->matrix[i]);
	}
	delete(this->matrix);
}

int node::print()
{
	/*
	for(int i = 0; i < this->size ; i++)
	{
		cout<<val[i]<<"||";
		for( int j = 0 ; j < this->size; j++)
		{
			cout<<"\t"<<this->matrix[i][j];
		}
		cout<<endl;
	}
	cout<<"========================"<<endl; 
	
	for(int i = 0; i < this->size ; i++)
	{
		cout<<"\t"<<valC[i];
		
		
	}
	cout<<endl;
	cout<<"========================"<<endl; 
	*/
	return 0;
}
