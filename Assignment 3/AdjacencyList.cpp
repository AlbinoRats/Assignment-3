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
	if (!contains(vertex.vertex, reverse.vertex)){
		addVertex(vertex.vertex, reverse);
	}
}

vector<node>& AdjacencyList::getVertices(const string & key) {
	return adjacencyList[key];
}


bool AdjacencyList::contains(const string & key, const string & vertex){
	if (find(getVertices(key).begin(), getVertices(key).end(), vertex) != getVertices(key).end()){
		return true;
	}
	return false;

}
void AdjacencyList::print(){
	for (map<string, vector<node> >::const_iterator it = adjacencyList.begin();
		it != adjacencyList.end(); ++it)
	{
		string key=it->first;
		cout <<"Key vertex: "<< key<<endl;
		cout<<"Names: \n";
		for(int i=0;i<adjacencyList[key].size();i++){
			cout<<adjacencyList[key][i].vertex<<endl;
			cout<<adjacencyList[key][i].weight<<endl;
		}
		cout << endl<<endl;
	}
	
	
}
