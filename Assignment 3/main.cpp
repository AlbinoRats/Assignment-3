#include<iostream>
#include<fstream>
#include <stdlib.h> 
#include<ostream>
#include <cstdlib>
#include<vector>
#include<string>
#include"AdjacencyList.h"
#include"Algorithms.h"
using namespace std;
void readIn(vector<string> & names) {
	ifstream input;
	input.open("marynames.txt");

	string name;
	while (!input.eof()) {
		getline(input, name);
		name = name.substr(0, name.size() - 1);
		names.push_back(name);

	}
	input.close();

}
void print(vector<string> &names) {
	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << endl;
	}
}

int main() {
	Algorithms algo;
	vector < string > names;
	readIn (names);

	AdjacencyList graph;

	while (names.size() != 0) {
		string name = names.back();

		names.pop_back();
		for (int i = 0; i < names.size(); i++) {
			int distance = algo.edit_distance(name, names[i]);

			if (distance <= 4) {

				node vertex;
				vertex.vertex = names[i];
				vertex.weight = distance;

				graph.addVertex(name, vertex);
			}
		}
	}
	//cout << "done\n";
	cout << "---- PRINTING GRAPH ----" << endl;
	graph.printSize();
	node minVertex = graph.getMinVertex("Mary");
	cout << minVertex.vertex << endl;
	//graph.print();

	system("pause");

}
