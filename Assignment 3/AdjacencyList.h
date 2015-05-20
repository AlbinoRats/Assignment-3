#ifndef ADJANCYLIST_H
#define ADJANCYLIST_H
#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
//node struct to hold the vertex and its corresponding weight
struct node{
	string vertex;
	int weight;
	//overloaded ==
	bool operator==(string const & rhs){
		return vertex == rhs;
	}
};

//AdjancyList
class AdjacencyList{
private:

	//Map that contains the string as the key, and a vector containing nodes as the adjacny vertices along with the weight to it.
	
	map<string, vector<node> > adjacencyList;
	
public:
	//constructor -- needs default values, ill fix it with initializer list
	AdjacencyList();

	//This takes care of adding a new key and or adding a new value into a corresponding key
	void addVertex(const string & key, const node & vertex);

	//returns the vector of values corresponding to the key
	vector<node> & getVertices(const string & key);

	//checks if a vertex is inside the vector of the key
	bool contains(const string & key, const string & vertex);
	//print
	void print();


};
#endif
