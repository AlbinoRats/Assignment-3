#include "AdjacencyList.h"

AdjacencyList::AdjacencyList() {

}

void AdjacencyList::addVertex(const string & key, const node & vertex) {
	//checks to see if the key is already inside the map, if so, it'll add the vertex into the vector of that key
	if (adjacencyList.find(key) != adjacencyList.end()) {
		adjacencyList[key].push_back(vertex);
	}
	//else adds the key into the map and add the vertex onto the vector
	else {
		vector<node> temp;
		temp.push_back(vertex);
		adjacencyList.insert(pair<string, vector<node> >(key, temp));
	}
	//for undirected graphs, basically calls addVertex on reversed parameter.
	node reverse;
	reverse.vertex = key;
	reverse.weight = vertex.weight;
	addVertex(vertex.vertex, reverse);
}

vector<node> AdjacencyList::getVertices(const string & key) {
	return adjacencyList[key];
}

/* THIS DOES NOT COMPILE - error: no matching function for call to 'find..*/
bool AdjacencyList::contains(const string & key, const string & vertex){
	if (find(getVertices(key).begin(), getVertices(key).end(), vertex) != getVertices(key).end()){
		return true;
	}
	return false;
	
}