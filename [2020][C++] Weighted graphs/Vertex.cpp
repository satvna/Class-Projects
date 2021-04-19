#include "Vertex.h"

Vertex::Vertex() {
	this->name = name;
	this->known = known;
	this->dist = dist;
	this->path = path;
	this->indegree = indegree;
	this->tempLine = tempLine;
}
Vertex::~Vertex(){
	name = ' ';
	known = false;
	dist = 0;
	path = ' ';
	indegree = 0;
	tempLine = "";
}

void Vertex::setName(char c){
	this->name = c;
}

char Vertex::getName() {
	return this->name;
}

void Vertex::setMap(char key, int value) {
	adj.insert(pair<char, int>(key, value));
}


int Vertex::mapSize() {
	int mapsize = 0;
	for (int i = 0; i < adj.size(); i++)
	{
		mapsize++;
	}
	return mapsize;
}

int Vertex::mapValue(char i) {
	int mapval = adj[i];
	return mapval; 
}

void Vertex::adjList() {
	map<char, int>::iterator it;
	for (it = adj.begin(); it != adj.end(); it++)
	{
		cout << "--> " << "(" << it->first << ", " << it->second << ")";
	}
}

void Vertex::setDist() {
	this->dist = dist;
}

void Vertex::dijkstra(char c) {
	cout << "dijkstra";

	
}

vector<char> Vertex::adjVector() {
	vector<char> v;
	map<char, int>::iterator it;  //for each vertex j adjacent to i
	for (it = adj.begin(); it != adj.end(); it++)
	{
		v.push_back(it->first);
	}

	return v;
}
int Vertex::getIndegree() {
	return this->indegree;
}
void Vertex::setIndegree(int i) {
	this->indegree = i;
}

void Vertex::topsort() {
	cout << "topsort";
	//perform sort
	//print results
}