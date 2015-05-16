#include "AdjancyList.h"

AdjancyList::AdjancyList(){}

void AdjancyList::addVertex(string key, node vertex){
	//checks to see if the key is already inside the map, if so, it'll add the vertex into the vector of that key
	if (adjancyList.find(key) != adjancyList.end())
	{
		adjancyList[key].push_back(vertex);
	}
	//else adds the key into the map and add the vertex onto the vector
	else
	{
		vector<node> temp;
		temp.push_back(vertex);
		adjancyList.insert(pair<string, vector<node>>(key, temp));
	}
	//for undirected graphs, basically calls addVertex on reversed parameter.
	node reverse;
	reverse.vertex = key;
	reverse.weight = vertex.weight;
		addVertex(vertex.vertex, reverse);
}

vector<node>AdjancyList::getVertices(string key){
	return adjancyList[key];
}
bool AdjancyList::contains(string key, string vertex){
	return find(getVertices(key).begin, getVertices(key).end, vertex);
}