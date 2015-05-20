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
void readIn(vector<string> & names){
	ifstream input;
	input.open("boynames.txt");
	
	string name;
	while (!input.eof()){
		getline(input, name);
		names.push_back(name);
	}
	
}
void print(vector < string > &names){
	for (int i = 0; i < names.size(); i++)
	{
		cout << names[i] << endl;
	}
}
int main(){
	Algorithms algo;
	vector<string> names;
	readIn(names);
	string name;
	AdjacencyList graph;
	while (names.size() != 0){
		name = names.back();
		names.pop_back();
		for (int i = 0; i < names.size(); i++){
			int distance = algo.edit_distance(name, names[i]);
			if (distance <= 4){
				node vertex;
				vertex.vertex = names[i];
				vertex.weight = distance;
				graph.addVertex(name, vertex);
			}
		}
	}
	cout << "done\n";
	graph.print();

	system("pause");

}
