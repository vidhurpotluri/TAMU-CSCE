#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "LocatorHeap.h"
#include <iostream>
#include <limits>
using namespace std;

class Edge;

class Vertex
{
public:
	int data;
	bool marked;
	vector<Edge *> edges;
	float d;
	Vertex *parent;
	Heap<Vertex>::Locator locator;

	Vertex ( int newData ) : data ( newData ) { }

	bool operator < ( const Vertex &v ) const 
	{ 
		return this->d < v.d;
	}
};

class Edge
{
public:
	Vertex *v1, *v2;
	float weight;

	Edge ( Vertex *nv1, Vertex *nv2, float newWeight ) : v1 ( nv1 ), v2 ( nv2 ), weight ( newWeight ) { }
};

// you should implement the adjacency list data structure
class Graph
{
public:
	vector<Vertex *> verts; // Array of vectors
	vector<Edge *> edges; // Array of edges
	Heap<Vertex> heap; // Locator heap of the vertices 

public:
	// Constructor function
	Graph ( void ) {
    }

    // Destructor function
	~Graph ( void )
	{
		verts.clear();
		edges.clear();
	}

	// Inserts vertex into verts array if the vertex doesn't already exist
	Vertex *insertVertex ( int data )
	{
		for (int i = 0; i < verts.size(); i++) {
			if (verts[i]->data == data) {
				return verts[i];
			}
		}

		Vertex *vert = new Vertex(data);
		verts.push_back(vert);
		for (int i = 0; i < verts.size(); i++) {
			//cout << verts[i]->data;
		}
		//cout << endl;
		return vert;
	}

	void insertEdge ( Vertex *v, Vertex *w, float weight )
	{
		Edge *edge = new Edge(v, w, weight);
		//cout << "edge" << endl;
		v->edges.push_back(edge);
		//cout << "v" << endl;
		w->edges.push_back(edge);
		//cout << "w" << endl;
		this->edges.push_back(edge);
	}

	// Calculates the shortest path from start vertex to end vertex based on Dijkstra’s shortest path algorithm.

	vector<Vertex *> shortestPath ( Vertex *start, Vertex *goal )
	{
		start->d = 0;
		start->parent = NULL;
		start->locator = heap.insertElement(start);
		// Inserting all elements of the verts vector with d values of infinity
		for (int i = 0; i < verts.size(); i++) {
			if (verts[i] != start) {
				verts[i]->d = numeric_limits<float>::max();
				verts[i]->parent = NULL;
				verts[i]->marked = false;
				verts[i]->locator = heap.insertElement(verts[i]);
				//cout << verts[i]->d << endl;
				//cout << heap.size();
			}
		}
		
		vector<Vertex *> path;
		Vertex *v;
		// Updates the d values as we traverse through the graph to goal
		while (heap.size() > 0 && v != goal) {
			//cout << heap.size() << endl;
			v = heap.removeMin(); // Removes and returns the top of the minHeap
			v->marked = true;
			for (int i = 0; i < v->edges.size(); i++) {
				Vertex *u = v->edges[i]->v2;
				if (u->marked == false){
					if (u->d > v->d + v->edges[i]->weight) {
						u->d = v->d + v->edges[i]->weight;
						u->parent = v;
						heap.update(u->locator);
						//cout << u->d << endl; // Debugging
					}
				}					
			}

			path.push_back(v); // Adds to the vector to be returned
			//cout << v->data << endl;

		}
		return path;

	}
};

#endif