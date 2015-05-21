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
void readIn(vector<string> & names, string filename){
	ifstream input;
	input.open(filename);

	string name = "";
	while (!input.eof()){
		getline(input, name);
		name = name.substr(0, name.size() - 1);
		names.push_back(name);

	}
	input.close();

}
void print(vector < string > &names){
	for (int i = 0; i < names.size(); i++)
	{
		cout << names[i] << endl;
	}
}
int main(int argc, char *argv[]){
	string filename = argv[1];
	//Prompts user to renter if does not meet condition
	if (argc != 2)
	{
		cout << "Please end the program and  re-enter one positive integer in the command line argument" << endl;
	}
	Algorithms algo;
	//stores all the names in the txt file into the vector
	vector<string> names;
	readIn(names,filename);

	AdjacencyList graph;
	//loop continues when the size of the vector is not 0
	while (names.size() != 0){
		//takes the last element in the vector, then pop it out
		string name = names.back();
		names.pop_back();
		//traverse through the rest of the vector and call the minimum edit distance on the element we just pop and the rest of the vector
		for (int i = 0; i < names.size(); i++){
			int distance = algo.edit_distance(name, names[i]);
			//if distance is <=4 we connect them inside the graph
			if (distance <= 4){

				node  vertex;
				vertex.vertex = names[i];
				vertex.weight = distance;

				graph.addVertex(name, vertex);
			}
		}
	}
	//cout << "done\n";

	//graph.print();
	graph.printSize();

	//system("pause");

}
