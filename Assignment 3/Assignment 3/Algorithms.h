#ifndef ALGORITHM_H
#define ALGORITHM_H
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include"AdjacencyList.h"
#include"BinaryHeap.h"
#include<stack>
#include<vector>
#include<queue>

/* Used to implement a STL minPriority Queue required for Prim's */
struct compare {
	bool operator()(const int& l, const int& r) {
		return l > r;
	}
};


using namespace std;
class Algorithms {
public:
	Algorithms() {

	}

	//MINIMUM EDIT DISTANCE FORMULA FROM WIKIPEDIA 
	unsigned int edit_distance(const string & s1, const string & s2) {

		const size_t len1 = s1.size(), len2 = s2.size();
		vector<vector<unsigned int> > d(len1 + 1,
				vector<unsigned int>(len2 + 1));

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

	void prims_algorithm(AdjacencyList &graph, AdjacencyList &MST) {
		int v = graph.getVertex();
		vector<string> keys;
		graph.getKeys(keys);

		//priority_queue<node,vector<int>, compare > pq;
		BinaryHeap<string> daHeap = BinaryHeap<string>(keys);

		while(!daHeap.isEmpty()) {
			string currentVertex;
			daHeap.deleteMin(currentVertex);
			node minVertex = graph.getMinVertex(currentVertex);
			MST.addVertex(currentVertex, minVertex);
		}
	}

	//depth first search
	/*The function takes in the minimum spanning tree(adjacencylist class), the starting vertex, the depth, a stack, and a vector container.
	 First it will mark the vertex as visisted, then push it into the stack then it will grab the corresponding vector of the vertex it will use the getMinVertex member function of the adjancency
	 list class on the starting vertex to grab the minimum weighted distant vertex from itself check for it's distant to see if its less than the depth
	 if it is, it will find the position of that vertex inside the correponding vector and remove it from the vector, then recursively call the function on that vertex

	 The function would first check to see if the vertex is null, if it is that it had traverse to the end of the current vertex and that there is no more route for this vertex
	 therefore it will pop from the stack and recursively call the function on the vertex that is popped from the stack. If the stack is empty it means we have finished.


	 */
	void DFS(AdjacencyList & var, node vertex, int depth, stack<node> & mystack,
			vector<node> & container) {
		if (vertex.vertex == "") {
			if (mystack.empty()) {

			} else {
				node back;
				back.vertex = mystack.top().vertex;
				back.visited = mystack.top().visited;
				back.weight = mystack.top().visited;
				mystack.pop();
				DFS(var, back, depth, mystack, container);
			}

		}

		vertex.visited = true;
		mystack.push(vertex);
		node min = var.getMinVertex(vertex.vertex);
		vector<node> myVec;
		var.getVertices(min.vertex, myVec);
		int weight = var.getWeight(vertex.vertex, min.vertex);
		if (weight <= depth) {
			vertex.vertex = min.vertex;
			vertex.weight = weight;
			vertex.visited = false;
			int pos = find(myVec.begin(), myVec.end(), vertex) - myVec.begin();
			swap(myVec[pos], myVec[myVec.size() - 1]);
			container.push_back(vertex);
			myVec.pop_back();
			DFS(var, vertex, depth, mystack, container);
		}

	}

};
#endif
