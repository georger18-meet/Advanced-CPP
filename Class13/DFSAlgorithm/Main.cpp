// DFS algorithm in C++
#include <iostream>
#include <list>
#include "Graph.h"
using namespace std;


int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.DFS(2);
    cout << endl;

    g.DisplayAdjList();

    return 0;
}

// *****************************************
// DFS Pseudocode (recursive implementation)
/*DFS(G, u)
u.visited = true
for each v ∈ G.Adj[u]
if v.visited == false
DFS(G, v)

init() {
    For each u ∈ G
        u.visited = false
        For each u ∈ G
        DFS(G, u)
}*/