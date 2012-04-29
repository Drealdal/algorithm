#include "node.h"
#include "nodecmp.h"
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
int solve(char *file);
#define INT_MAX 0XeFFF

int main(int argc, char *argv[])
{
	char *file = "./data.txt";
	if(argc < 2 )
	{
		cout<<"Usage: /path/to/input"<<endl;
		cout<<"Using default: ./data.txt"<<endl;
	}else{
		file = argv[1];
	}
	solve(file);
	return 0;
}
int solve(char *file)
{
	ifstream fin(file);
	node root(fin);
	priority_queue<node *,vector<node *>,nodecmp> E;
	E.push(&root);

	int minval = INT_MAX;
	node *answer = NULL;
	while(!E.empty())
	{
		node *top = E.top();
		if(top->cost >= minval )
		{
			E.pop();
			continue;
		}
		if( top->size == 0)
		{
			
			if(  top->cost < minval )
			{
				minval = top->cost;
				node * tmp = answer;
				top->print();
				answer = top;
				delete(tmp);
			}
			    /* cout<<"New Best Cost("<<answer->cost<<"):"<<endl;
			}else{
			    cout<<"Solution (Cost:"<<top->cost<<")"<<endl;
			}
			for(int i = 0; i < top->length; i++ )
			{
				cout<<top->answer[i]<<"==>";
			}

			cout<<1<<endl;
			*/
			E.pop();
			continue;
		
		}
	    node *l = top->go();
		if( l == NULL) 
		{
			E.pop();
			continue;
		}
	
		E.push(l);
	
	}
	if(answer == NULL)
	{
		cout<<"NON"<<endl;
	}else{
		cout<<answer->cost<<endl;
/*		for(int i = 0; i < answer->length; i++ )
		{
			cout<<answer->answer[i]<<"==>";
		}
		cout<<1<<endl;
	*/
	}
	return 0;
}
