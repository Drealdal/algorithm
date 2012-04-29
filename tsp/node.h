#ifndef _NODE_H
#define _NODE_H
#include<iostream>
#include<fstream>
class node
{
public:
	int pSize;
	int cur_pos;
	int size;
	int cost;
	int cur;
	int length;
	int *answer;
	int *val;
	int *valC;
	int **matrix;

	node * go();
	node();
	node(std::ifstream &fin);
	~node();
	int print();

};

#endif