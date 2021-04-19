/*Sarah Tavana
CSCE 3110.021
Program that manipulates a weighted directed graph. */


#include <iostream>
#include <map> 
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Vertex.h"
using namespace std; 

void indegree(vector<Vertex> graph) {
    //loop through graphs
    for (int i = 0; i < graph.size(); i++) {
        //call adjVector for each
        vector<char> adjVectors = graph.at(i).adjVector();

        for (int j = 0; j < adjVectors.size(); j++) {//loop through adjVector
            int tempdegree = 0;
            //for each adjVector, loop graphs again
            for (int k = 0; k < graph.size(); k++) {
                if (graph.at(k).getName() == adjVectors.at(j)) {  //find matching key
                   
                    tempdegree = graph.at(k).getIndegree() + 1;
                    graph.at(k).setIndegree(tempdegree);

                }
            }


        }
    }
        //print  
        for (int i = 0; i < graph.size(); i++) {
            cout << graph.at(i).getName() << " : " << graph.at(i).getIndegree() << endl;
        }
 }


    int main() {

        string fileName; //to hold the filename
        int fileChoice; //to hold option choice 1-5

        char shortestPath; //holds vertex for shortest path operation

        vector<Vertex> graph;
        //prompt and read in data files 

        std::cout << "Enter the name of the input file: ";
        getline(cin, fileName, '\n');

        ifstream infile;
        string line;


        infile.open(fileName);
        while (infile.good()) {
            Vertex tempVertex;
            (getline(infile, line));
            tempVertex.setName(line.at(0));
            
           
            map<char, int> tempMap;
            char key = ' ';
            int value = 0;

            istringstream iss(line);
            string token;
            char* charToken;

            while (std::getline(iss, token, ' '))
            {
                charToken = const_cast<char*>(token.c_str());
                char newChar = *charToken;
          
                if (*charToken != tempVertex.getName()) {
                   

                    if (isdigit(newChar)) {

                        value = newChar - '0';

                    }
                    else if (isalpha(newChar)) {
                      
                        key = newChar;
                        
                        tempVertex.setMap(key, value);
                        key = ' ';
                        value = 0;
                    }
                    else {
                        cout << "File contains invalid character." << endl;
                    }
                }


            }

            graph.push_back(tempVertex);

        }

        do {
            cout << "Enter option choice 1-5: \n(1) Print Adjacency List\n(2) Print Single-Source Shortest Path\n(3) Print Indegree of Each Vertex\n(4) Print Topological Sort of Graph\n(5) Exit Program\n";
            cin >> fileChoice;

            /*---------------ADJACENCY LIST----------------*/
            if (fileChoice == 1) {
                cout << "Adjacency List:" << endl;
                for (int i = 0; i < graph.size(); i++) { //iterate through vector
                    cout << graph.at(i).getName() << " : ";
                    graph.at(i).adjList();
                    cout << endl;
                }

            }
            /*--------------SHORTEST PATH------------------*/
            else if (fileChoice == 2) {

            }

            /*--------------INDEGREE-----------------------*/
            else if (fileChoice == 3) {
                cout << "Indegree of Each Vertex:" << endl;
                indegree(graph);

            }
            /*--------------TOPOLOGICAL SORT--------------------*/
            else if (fileChoice == 4) {
                cout << "Topological Sort of Graph: " << endl;

            }
            else {
                if (fileChoice != 5) {
                    cout << "Not a valid option. Please choose a number between 1 and 5." << endl;
                }
            }
        } while (fileChoice != 5);


        cout << "Terminating program..." << endl;
        return 0;
    }


