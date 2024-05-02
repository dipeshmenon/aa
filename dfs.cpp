
#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int> >& adjList, vector<bool>& visited, int current) {
    visited[current] = true;
    cout << current << " ";

    for (int i = 0; i < adjList[current].size(); ++i) {
        int neighbor = adjList[current][i];
        if (!visited[neighbor]) {
            DFS(adjList, visited, neighbor);
        }
    }
}

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int> > adjList(V); // Adjacency list representation
    vector<bool> visited(V, false); // Array to keep track of visited vertices

    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Assuming undirected graph
        adjList[v].push_back(u);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "Depth First Search (DFS) starting from vertex " << startVertex << ":" << endl;
    DFS(adjList, visited, startVertex);

    return 0;
}
