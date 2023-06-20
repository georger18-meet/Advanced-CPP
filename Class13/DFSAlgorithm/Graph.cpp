#include "Graph.h"

// Initialize graph
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_front(dest);
}

// DFS algorithm
void Graph::DFS(int vertex) {
    visited[vertex] = true;
    list<int> adjList = adjLists[vertex];

    cout << vertex << " ";

    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

void Graph::DisplayAdjList()
{
    for (int i = 0; i < adjLists->size(); i++)
    {
        cout << adjLists[i].size() << ",";
        for (int j = 0; j < adjLists[i].size(); j++)
        {
            //cout << to_string(adjLists[i][j]) << endl;
        }

    }
}
