#ifndef ADJANCYLIST_H
#define ADJANCYLIST_H
#include<iostream>
#include<string.h>
#include<vector>
#include<map>

using namespace std;
//node struct to hold the vertex and its corresponding weight
struct node{
	string vertex;
	int weight;
};
//AdjancyList
class AdjancyList{
private:
	//Map that contains the string as the key, and a vector containing nodes as the adjacny vertices along with the weight to it.
	map<string, vector<node>> adjancyList;
	
public:
	//constructor
	AdjancyList();
	//This takes care of adding a new key and or adding a new value into a corresponding key
	void addVertex(string key, const node vertex);
	//returns the vector of values corresponding to the key
	vector<node> getVertices(string key);
	//checks if a vertex is inside the vector of the key
	bool contains(string key, string vertex);


};
#endif