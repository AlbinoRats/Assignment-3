#include "Algorithms.h"

//it said algorithm was redefined with that constructor, i dont think you need to restate it if its empty

void prims_algorithm() {
	// find the smallest vertex somehow -- probably an AL.h function looking thru the map's values
	// each vertex needs a key
	// initialize all keys to infinity

	}

unsigned int Algorithms::edit_distance(const string & s1, const string & s2) {

	const size_t len1 = s1.size(), len2 = s2.size();
	vector<vector<unsigned int> > d(len1 + 1, vector<unsigned int>(len2 + 1));

	d[0][0] = 0;
	for (unsigned int i = 1; i <= len1; ++i)
		d[i][0] = i;
	for (unsigned int i = 1; i <= len2; ++i)
		d[0][i] = i;

	for (unsigned int i = 1; i <= len1; ++i)
		for (unsigned int j = 1; j <= len2; ++j)
			// note that min({arg1, arg2, arg3}) works only in C++11,
			// for C++98 use min(min(arg1, arg2), arg3)
			d[i][j] = min(
					{ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1]
							+ (s1[i - 1] == s2[j - 1] ? 0 : 1) });
	return d[len1][len2];

}
//void Algorithms::DFS(AdjacencyList &var,node vertex,int depth, stack<node> & mystack){
//	//stack<node> myStack;
//	if (vertex.vertex == ""){
//		node back;
//		back.vertex	=mystack.top().vertex;
//		back.visited = mystack.top().visited;
//		back.weight = mystack.top().visited;
//		mystack.pop();
//		DFS(var,back,depth,mystack);
//		
//	}
//	vertex.visited = true;
//	mystack.push(vertex);
//	node min = var.getMinVertex(vertex.vertex);
//	vector<node> myVec;
//	var.getVertices(min.vertex, myVec);
//	int weight = var.getWeight(vertex.vertex, min.vertex);
//	if ( weight<= depth){
//		vertex.vertex = min.vertex;
//		vertex.weight = weight;
//		vertex.visited = false;
//		int pos = find(myVec.begin(), myVec.end(), vertex) - myVec.begin();
//		swap(myVec[pos], myVec[myVec.size() - 1]);
//		myVec.pop_back();
//		DFS(var, vertex, depth, mystack);
//	}
//	
//
//}
