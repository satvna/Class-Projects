#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Vertex {
public:
    Vertex();
    ~Vertex();

    //setters and getters
    void setName(char c); 
    char getName();

    void setMap(char key, int value);
    int mapSize();

    int mapValue(char i);
    void adjList();

    void setDist();

    int getIndegree();
    void setIndegree(int i);
    //main functions

    void dijkstra(char c); //shortest path function
    vector<char> adjVector(); //returns vector of the names of the adjacent nodes
    
    void topsort(); //finds topological sort of graph
private:
    char            name;
    map<char, int>  adj;
    bool            known;
    int             dist;
    char            path;
    int             indegree;
    string          tempLine; //to hold line read in by file

};