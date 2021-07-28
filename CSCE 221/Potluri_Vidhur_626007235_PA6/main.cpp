#include "Graph.h"
#include<iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
using namespace std; 

/*
create two graphs, one adjacency matric, and one adjacency list of 5 verticies each
insert the same three edges in both graphs
*/
int main(){
 

    Graph l = Graph(); 

    /*
    l.insertEdge(l.insertVertex(0), l.insertVertex(2), 1);
    l.insertEdge(l.insertVertex(1), l.insertVertex(2), 5);
    l.insertEdge(l.insertVertex(2), l.insertVertex(3), 3);
    l.insertEdge(l.insertVertex(1), l.insertVertex(3), 2);
    l.insertEdge(l.insertVertex(0), l.insertVertex(3), 10);


    vector<Vertex *> x = l.shortestPath(l.verts[1], l.verts[2]);
    int i = 0;
    while (i < x.size()) {
        cout << x[i]->data << endl;
        i++;
    }*/

    char filename[] = "";
   
    cout << "Enter a file name: " ;
    cin >> filename;
   

    ifstream inFile(filename);

    // Error message if file isn't valid
    if (!inFile) {
        cerr << "Unable to open file " << filename << endl;
        exit(1);
    }

    int n; // Number of vertices
    int m; // Number of edges


    
    inFile >> n;
    inFile >> m;

    // Creating the graph
    int i = 0; // iterator
    while (i < m) {
        int v1,v2;
        float e;
        inFile >> v1;
        inFile >> v2;
        inFile >> e;
        l.insertEdge(l.insertVertex(v1),l.insertVertex(v2),e);
        //cout << v1 << " " << v2 << " " << e << endl;
        i++;
    }

    // Shortest path calculation
    int start, goal;
    inFile >> start;
    inFile >> goal;
    Vertex* startV = l.insertVertex(start);
    Vertex *goalV = l.insertVertex(goal);

    vector<Vertex *> path = l.shortestPath(startV, goalV);
    
   int a = 0;
    while (a < path.size()) {
        cout << path[a]->data;
        if (a != path.size()-1) {cout << ",";}
        a++;
    }
    



    inFile.close();
}
