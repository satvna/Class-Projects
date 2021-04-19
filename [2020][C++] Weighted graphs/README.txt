This program finds attributes of a weighted, directed graph from the
.txt file specified by the user.

Each line of the .txt file starts with the vertex, then describes the 
vertexes it points to. For example, in the following line:

			B 6 D 5 E

B is the vertex, which points to D and E with weights 6 and 5.

User can generate the following information of the graph with this program:
(1) Adjacency list 
(2) Single-Source shortest path
(3) Indegree of each vertex 
(4) Topological sort
--------------------------------------------------------------------------------

To run in Linux:
-- g++ Vertex.h Vertex.cpp project4-3110.cpp
-- ./a.out

"move in1.txt" is provided as a sample input file.
