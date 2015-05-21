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
	bool visited = false;
	//overloaded ==
	bool operator==(string const & rhs) {
		return vertex == rhs;
	}
	bool operator ==(node const &rhs) {
		return vertex == rhs.vertex;
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
	AdjacencyList() {
		totalEdges = 0;
		//adjacencyList=new map<string,vector<node>>();
	}
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
		//cout<<adjacencyList["Mary"].size()<<endl;
	}
	//returns the vector of nodes that are connected to key in adjacencyList
	void getVertices(const string & key, vector<node> & vertices) {
		vertices = adjacencyList[key];
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
		cout << "SIZE:" << adjacentVecs.size() << endl;
		for (auto i : adjacentVecs) {
			if (i.weight < minWeight) {
				minWeight = i.weight;
				minNode = i;
				cout << "Vertex:" << i.vertex << endl;
			}
		}
		return minNode;
	}
	//returns the weight of a vertex and the key
	int getWeight(const string&key, const string&vertex) {
		vector<node>::iterator it;
		it = find(adjacencyList[key].begin(), adjacencyList[key].end(), vertex);
		if (it != adjacencyList[key].end()) {
			node found = *it;
			return found.weight;
		}
	}
	//prints the whole map
	void print() {
		for (map<string, vector<node> >::const_iterator it =
				adjacencyList.begin(); it != adjacencyList.end(); ++it) {
			string key = it->first;
			cout << "Key vertex: " << key << " " << key.length() << endl;
			cout << "Names: \n";
			for (int i = 0; i < adjacencyList[key].size(); i++) {
				cout << adjacencyList[key][i].vertex << " "
						<< adjacencyList[key][i].weight << " ";
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
