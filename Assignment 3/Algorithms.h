#ifndef ALGORITHM_H
#define ALGORITHM_H

#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include"AdjacencyList.h"
#include<stack>

//you also named the class same as your include file, which might cause kind of a conflict
using namespace std;
class Algorithms{
public:
	Algorithms(){

	}
	//MINIMUM EDIT DISTANCE FORMULA FROM WIKIPEDIA (because I'm a lazy fuck)
	unsigned int edit_distance(const string & s1, const string & s2);

	//PUT PRIMS HERE
	// dont tell me what to do
	void prims_algorithm();
	void DFS(AdjacencyList & var, node vertex,int depth,stack<node> & mystack);
	//YOU'LL DO WHAT I TELL YOU TO DO

};
#endif
