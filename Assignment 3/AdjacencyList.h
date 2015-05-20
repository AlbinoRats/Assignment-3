#ifndef ADJANCYLIST_H
#define ADJANCYLIST_H
#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
//node struct to hold the vertex and its corresponding weight
struct node {
	string vertex;
	int weight;
	//overloaded ==
	bool operator==(string const & rhs) {
		return vertex == rhs;
	}
};

//AdjancyList
class AdjacencyList {
private:
	//Map that contains the string as the key, and a vector containing nodes as the adjacny vertices along with the weight to it.
	map<string, vector<node> > adjacencyList;

	int totalEdges;
public:
	//constructor -- needs default values, ill fix it with initializer list
	AdjacencyList() :
			totalEdges { 0 } {
	}
	;
	//inserts vertex into adjacencylist, it will take care of undirect graph and dupes.
	void addVertex(const string & key, const node & vertex) {
		//checks to see if the key is already inside the map, if so, it'll add the vertex into the vector of that key

		if (adjacencyList.find(key) != adjacencyList.end()) {
			totalEdges++;
			adjacencyList[key].push_back(vertex);
		}
		//else adds the key into the map and add the vertex onto the vector
		else {
			vector<node> temp;
			temp.push_back(vertex);
			totalEdges++;

			adjacencyList.insert(pair<string, vector<node> >(key, temp));
		}
		//for undirected graphs, basically calls addVertex on reversed parameter.

		node reverse;
		reverse.vertex = key;
		reverse.weight = vertex.weight;
		if (!contains(vertex.vertex, reverse.vertex)) {
			addVertex(vertex.vertex, reverse);
		}
	}
	//returns the vector of nodes that are connected to key in adjacencyList
	void getVertices(const string & key, vector<node> & vertices) {
		vertices = adjacencyList[key];
		cout << adjacencyList[key].size() << endl;
	}

	//checks if a name is connected to a key
	bool contains(const string & key, const string & vertex) {
		vector<node> vertices;
		getVertices(key, vertices);
		if (find(vertices.begin(), vertices.end(), vertex) != vertices.end()) {
			return true;
		}
		return false;

	}
	node getMinVertex(const string & key) {

		int minWeight = numeric_limits<int>::max();
		node minNode;

		vector<node> adjacentVecs;
		getVertices(key, adjacentVecs);
		cout << adjacentVecs.size() << endl;
		for (auto i : adjacentVecs) {
			if (adjacentVecs[i].weight < minWeight) {
				minWeight = adjacentVecs[i].weight;
				minNode = adjacentVecs[i];
			}
		}
		return minNode;
	}
	//prints the whole map
	void print() {
		for (map<string, vector<node> >::const_iterator it =
				adjacencyList.begin(); it != adjacencyList.end(); ++it) {
			string key = it->first;
			cout << "Key vertex: " << key << endl;
			cout << "Names: \n";
			for (int i = 0; i < adjacencyList[key].size(); i++) {
				cout << adjacencyList[key][i].vertex << endl;
				cout << adjacencyList[key][i].weight << endl;
			}
			cout << endl << endl;
		}

	}
	//prints edge amount and vertices amount
	void printSize() {
		cout << "Total number of Vertices: " << adjacencyList.size() << endl;
		cout << "Total number of Edges: " << totalEdges << endl;
	}

};
#endif
