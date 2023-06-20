#pragma once
#include <iostream>
#include <list>
#include <string> 
using namespace std;

class Graph {
    int numVertices;
    list<int>* adjLists;
    bool* visited;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
    void DisplayAdjList();
};